/**
 * @name MineSweeper
 * @brief Demineur simple sans interface graphique.
 *
 * @authors BadiiiX & Beowulf
 * @version 0.0.1
 */

#include <iostream>
#include <string>
#include <ctime>

#include "Grille.h"

int main() {

    srand((unsigned) time(NULL));

    int cmd;

    std::cin >> cmd;
    switch (cmd) {

        case 1:
            createProblem();
            break;

        case 2:
        case 3:
        case 4:
            createGrille(cmd);
            break;

        case 5:
            readGrille();
            break;

    }
}