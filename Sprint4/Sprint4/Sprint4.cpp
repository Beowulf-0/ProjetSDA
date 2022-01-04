/**
 * @name MineSweeper
 * @brief Démineur simple sans interface graphique.
 *
 * @authors BadiiiX & Beowulf
 * @version 0.0.1
 */

#include <iostream>
#include <string>
#include <ctime>

#include "Grille.h"

int main() {

	srand((unsigned)time(NULL));

	int cmd;
	bool loop = true;

	while (loop) {
		//WARNING: If cmd get a string, loop can be infinite ;(
		std::cin >> cmd;
		switch ((int)cmd) {
		case 1:
			createProblem();
			break;

		case 2:
			createGrille();
			break;

		case 3:
			gameWon();
			break;

		case 4:
			gameLost();
			break;

		case 5:
			break;

		case 6:
			loop = false;

		default:
			std::cout << "Commande inconnue";
			break;

		}
	}
}