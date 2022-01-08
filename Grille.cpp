#include "Grille.h"
#include <iostream>

bool detectedMines(Grille &gr, unsigned int x, unsigned int y) {
    return gr.tab[x][y].content == CONTENT::MINE;
}

bool validCase(Grille &gr, unsigned int x, unsigned int y) {
    return (x >= 0 && x < gr.pb.lineNumber) && (y >= 0 && y < gr.pb.columnNumber);
}

void placeMines(Grille &gr) {
    for (unsigned m = 0; m < gr.pb.mineNumber; m++) {
        Mine mine = gr.pb.mineLoc[m];
        unsigned line = mine / gr.pb.columnNumber,
                column = mine % gr.pb.columnNumber;
        if (validCase(gr, line, column)) gr.tab[line][column].content = CONTENT::MINE;
    }
}

void setMines(Grille &gr) {
    for (unsigned m = 0; m < gr.pb.mineNumber; m++) {
        Mine mineLoc;

        std::cin >> mineLoc;
        gr.pb.mineLoc[m] = mineLoc;
    }
}

void demask(Grille &gr, unsigned int x, unsigned int y) {
    enum {
        TESTS_TO_DO = 8
    };
    unsigned int toTest[TESTS_TO_DO][2] =
            {
                    {x + 0, y + 1},
                    {x + 0, y - 1},
                    {x + 1, y + 0},
                    {x + 1, y + 1},
                    {x + 1, y - 1},
                    {x - 1, y + 0},
                    {x - 1, y + 1},
                    {x - 1, y - 1},
            };

    Case *c = &(gr.tab[x][y]);
    c->state = STATE::SHOWED;

    //Showing all mines
    if (c->content == CONTENT::MINE) {
        for (unsigned i = 0; i < gr.pb.mineNumber; i++) {
            unsigned line = gr.pb.mineLoc[i] / gr.pb.columnNumber,
                    column = gr.pb.mineLoc[i] % gr.pb.columnNumber;
            gr.tab[line][column].state = STATE::SHOWED;
        }
    }

    if (c->content != CONTENT::VOID) return; //Condition d'arrêt finale

    for(unsigned i = 0; i < TESTS_TO_DO; i++) {
        unsigned *test = toTest[i];
        if (validCase(gr, test[0], test[1]) && (gr.tab[test[0]][test[1]]).state == STATE::HIDED) { //condition de récursivité (sécurité)
            demask(gr, test[0], test[1]);
        }
    }
}

unsigned minesNearby(Grille &gr, unsigned int x, unsigned int y) {
    if (detectedMines(gr, x, y)) return 0;

    unsigned int mineCount = 0;
    enum {
        TESTS_TO_DO = 8
    };
    unsigned int toTest[TESTS_TO_DO][2] =
            {
                    {x + 0, y + 1},
                    {x + 0, y - 1},
                    {x + 1, y + 0},
                    {x + 1, y + 1},
                    {x + 1, y - 1},
                    {x - 1, y + 0},
                    {x - 1, y + 1},
                    {x - 1, y - 1},
            };

    for(unsigned i = 0; i < TESTS_TO_DO; i++) {
        unsigned *test = toTest[i];
        if (validCase(gr, test[0], test[1])
            && detectedMines(gr, test[0], test[1]))
            mineCount++;
    }

    return mineCount;
}

void setStroke(Grille &gr) {
    for (unsigned int str = 0; str < gr.histo.nbrStrokes; str++) {
        char stroke;
        unsigned int pos;
        std::cin >> stroke >> pos;
        gr.histo.strokes[str].letter = stroke;
        gr.histo.strokes[str].pos = pos;
    }
}

void executeStroke(Grille &gr) {
    for (unsigned i = 0; i < gr.histo.nbrStrokes; i++) {
        unsigned line = gr.histo.strokes[i].pos / gr.pb.columnNumber,
                column = gr.histo.strokes[i].pos % gr.pb.columnNumber;

        switch (gr.histo.strokes[i].letter) {
            case 'M':
                if (validCase(gr, line, column))
                    gr.tab[line][column].state = MARKED;
                break;
            case 'D':
                if (validCase(gr, line, column)) demask(gr, line, column);
                break;
        }
    }
}

void printGrid(const Grille &g) {
    unsigned lines = g.pb.lineNumber,
            columns = g.pb.columnNumber;

    std::cout << lines << " " << columns << "\n";
    for (unsigned int i = 0; i < lines; i++) {
        for (unsigned _ = 0; _ < columns; _++) {
            std::cout << " ___";
        }
        std::cout << "\n";
        for (unsigned int j = 0; j < columns; j++) {
            std::cout << ((j == 0) ? "| " : " ")
                      << showElement(g.tab[i][j])
                      << " |";
        }
        std::cout << "\n";
    }
    for (unsigned _ = 0; _ < columns; _++) {
        std::cout << " ___";
    }
    std::cout << "\n";
}

void fillGrid(Grille &gr) {
    unsigned lines = gr.pb.lineNumber,
            columns = gr.pb.columnNumber;

    placeMines(gr);

    for (unsigned i = 0; i < lines; i++) {
        for (unsigned j = 0; j < columns; j++) {
            if (gr.tab[i][j].content != CONTENT::MINE) gr.tab[i][j].content = minesNearby(gr, i, j);
            gr.tab[i][j].state = STATE::HIDED;
        }
    }
}

void generateGrid(Grille &gr) {
    gr.tab = new Case *[gr.pb.lineNumber];
    for (unsigned i = 0; i < gr.pb.lineNumber; i++) {
        gr.tab[i] = new Case[gr.pb.columnNumber];
    }
}

bool isWon(Grille &gr) {
    unsigned int lines = gr.pb.lineNumber, columns = gr.pb.columnNumber;

    for (unsigned int i = 0; i < lines; i++) {
        for (unsigned int j = 0; j < columns; j++) {
            Case *bloc = &gr.tab[i][j];

            if (bloc->content == CONTENT::VOID && bloc->state == STATE::HIDED) return false;
            if (bloc->content == CONTENT::MINE && bloc->state != STATE::MARKED) return false;
        }
    }
    return true;
}

bool isLost(const Grille &gr) {
    unsigned lines = gr.pb.lineNumber, columns = gr.pb.columnNumber;

    for (unsigned i = 0; i < lines; i++) {
        for (unsigned j = 0; j < columns; j++) {
            Case *bloc = &gr.tab[i][j];

            if (bloc->content == CONTENT::MINE && bloc->state == STATE::SHOWED) return true;
            if (bloc->content != CONTENT::MINE && bloc->state == STATE::MARKED) return true;
        }
    }
    return false;

}

void deleteGrille(Grille &gr) {
    for (unsigned i = 0; i < gr.pb.lineNumber; i++) {
        delete[] gr.tab[i];
    }
    delete[] gr.tab;
    deleteHisto(gr.histo);
    deleteProblem(gr.pb);
}

void createGrille(unsigned command) {
    unsigned line, column, nbrMine;
    Grille gr{};

    std::cin >> line >> column >> nbrMine;

    defineProblem(gr.pb, line, column, nbrMine);
    generateGrid(gr);
    setMines(gr);

    fillGrid(gr);

    //Stroke System
    defineHisto(gr.histo);
    setStroke(gr);
    executeStroke(gr);

    if (command == 3) std::cout << (isWon(gr) ? "game won" : "game not won") << std::endl;
    else if (command == 4) std::cout << (isLost(gr) ? "game lost" : "game not lost") << std::endl;
    else printGrid(gr);

    //delete memory
    deleteGrille(gr);
}


void readGrille() {
    unsigned lineNum, colNum;
    std::cin >> lineNum >> colNum;

    for (unsigned i = 0; i < lineNum; i++) {
        unsigned charForLine = colNum * 4 + 1, // values line | . | x | n |
        charForSeparator = 3 * colNum + colNum + 2; //Separators line, ___ ___ ___

        std::cin.ignore(charForSeparator); //ignore seperator line

        char line[charForLine];
        std::cin.read(line, sizeof(line)); //read whole line, with spaces

        for (unsigned j = 2; j < charForLine; j += 4) {
            if (line[j] == '.') {
                unsigned getCaseNumber = i * colNum + (j / 4);
                std::cout << 'D' << getCaseNumber;
                return;
            }
        }

        std::cout << "Aucun coup déterminé.";
    }
}