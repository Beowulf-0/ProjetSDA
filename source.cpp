/**
 * @name MineSweeper
 * @brief Démineur simple sans interface graphique.
 *
 * @authors BadiiiX & Beowulf
 * @version 0.0.1
 */

#include <iostream>
#include <random>
#include <string>

enum LIMITS {
    COLUMNS = 32,
    LINES = 32
};

enum ELEMENTS {
    BOMB = 1,
    VOID = 0,
    VIEWED = -1
};

typedef int Mine;

struct Problem {
    unsigned lineNumber;
    unsigned columnNumber;
    unsigned mineNumber;
    Mine *mineLoc;
};

struct Grille {
    Problem pb;
    unsigned **tab;
};


void generateMine(Problem *pb, Mine *mineList);

void defineProblem(Problem *pb, unsigned lines, unsigned column, unsigned mines);

void generateGrid(Grille *gr);

void defineProblem(Problem *pb, unsigned lines, unsigned column, unsigned mines) {
    pb->lineNumber = lines;
    pb->columnNumber = column;
    pb->mineNumber = mines;
    pb->mineLoc = new Mine[pb->mineNumber];
}

void generateMine(Problem *pb, Mine *mineList) {
    //TODO: Security about Problem

    for (int m = 0; m < pb->mineNumber; m++) {
        unsigned int maxValue = pb->columnNumber * pb->lineNumber;
        mineList[m] = std::rand() % maxValue;
    }
}

void setMines(Grille *gr) {
    for(unsigned m = 0; m < gr->pb.mineNumber; m++) {
        int mineLoc;
        std::cin >> mineLoc;
        gr->pb.mineLoc[m] = mineLoc;
    }
}

void generateGrid(Grille *gr) {
    gr->tab = new unsigned *[gr->pb.lineNumber];
    for (int i = 0; i < gr->pb.lineNumber; i++) {
        gr->tab[i] = new unsigned[gr->pb.columnNumber];
    }
}

void printGrid(const Grille *g) {
    unsigned lines = g->pb.lineNumber,
            columns = g->pb.columnNumber;

    std::cout << lines << " " << columns << std::endl;
    for (unsigned int i = 0; i < lines; i++) {
        for (unsigned _ = 0; _ < columns; _++) {
            std::cout << " ___";
        }
        std::cout << std::endl;
        for (unsigned int j = 0; j < columns; j++) {
            //Todo, create function to show elemnt about his value
            std::cout << ((j == 0) ? "| " : " ") << g->tab[i][j] << " |";
        }
        std::cout << std::endl;
    }
    for (unsigned _ = 0; _ < columns; _++) {
        std::cout << " ___";
    }
}

void fillGrid(Grille *g) {
    unsigned lines = g->pb.lineNumber,
            columns = g->pb.columnNumber;

    for (unsigned int i = 0; i < lines; i++) {
        for (unsigned int j = 0; j < columns; j++) {
            unsigned readableNum = i * lines + j;
            for(int m = 0; m < g->pb.mineNumber; m++) {
                if(g->pb.mineLoc[m] == readableNum) {
                    g->tab[i][j] = ELEMENTS::BOMB;
                }
            }
            if(g->tab[i][j] != ELEMENTS::BOMB) g->tab[i][j] = ELEMENTS::VOID;
        }
    }
}


void createProblem() {
    unsigned line, column, mines;
    Problem problem{};

    std::cin >> line >> column >> mines;

    //Generate mines
    problem.lineNumber = line;
    problem.columnNumber = column;
    problem.mineNumber = mines;
    problem.mineLoc = new Mine[problem.mineNumber];
    generateMine(&problem, problem.mineLoc);


    std::cout << problem.lineNumber << " " << problem.columnNumber << " " << problem.mineNumber << " ";
    for (int i = 0; i < problem.mineNumber; i++) {
        std::cout << problem.mineLoc[i] << " ";
    }

    std::cout << std::endl;

    //delete memory
    delete[] problem.mineLoc;
}

void createGrille() {
    unsigned line, column, nbrMine;
    Grille gr{};

    std::cin >> line >> column >> nbrMine;

    defineProblem(&gr.pb, line, column, nbrMine);
    generateGrid(&gr);
    setMines(&gr);
    fillGrid(&gr);
    printGrid(&gr);

    //delete memory
    for (int i = 0; i < line; i++) {
        delete[] gr.tab[i];
    }
    delete[] gr.tab;

}

int main() {

    srand(time(NULL));

    int cmd;
    bool loop = true;

    while (loop) {
        std::cin >> cmd;
        switch (cmd) {
            case 1:
                createProblem();
                break;

            case 2:
                createGrille();
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                break;

            case 6:
                loop = false;

            default:
                std::cin.ignore(17, '\n');
                std::cout << "Commande inconnue" << std::endl;

        }
    }
}