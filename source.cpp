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

//Définitions:
enum LIMITS {
    COLUMNS = 32,
    LINES   = 32
};

enum ELEMENTS {
    BOMB   = 1,
    VOID   = 0,
    VIEWED = -1
};


typedef int  Mine;
typedef char Stroke;


struct Problem {
    unsigned int lineNumber;
    unsigned int columnNumber;
    unsigned int mineNumber;
    Mine         *mineLoc;
};

struct Grille {
    int **tab;
};


/**
 *
 */
void createProblem();

/**
 *
 * @param pb
 * @param mineList
 */
void generateMine(Problem *pb, Mine *mineList);

void generateMine(Problem *pb, Mine *mineList) {
    //TODO: Security about Problem

    for (int m = 0; m < pb->mineNumber; m++) {
        unsigned int maxValue = pb->columnNumber * pb->lineNumber;
        mineList[m] = std::rand() % maxValue;
    }
}


void createProblem() {
    unsigned int line, column, mines;
    Problem      problem {};

    std::cin >> line >> column >> mines;

    //Generate mines
    problem.lineNumber   = line;
    problem.columnNumber = column;
    problem.mineNumber   = mines;
    problem.mineLoc      = new Mine[problem.mineNumber];

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
    //Todo à vérifier, car pas sûr.
    //LIMITS
    //LINE = LIMITS::LINES /:\ COLUMN = LIMITS::COLUMNS
    unsigned int line = 7, column = 15;
    Grille       gr {};
    //Tab Init
    gr.tab = new int *[line];
    for (int i = 0; i < line; i++) {
        gr.tab[i] = new int[column];
    }

    //Now tab can be access with : tab[value][value];
    //BOMB = ELEMENTS::BOMB
    //VOID = ELEMENTS::VOID
    //VIEWED = ELEMENTS::VIEWED

    //delete memory
    for (int i = 0; i < line; i++) {
        delete[] gr.tab[i];
    }
    delete[] gr.tab;

}

int main() {

    srand(time(NULL));

    int  cmd;
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