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
#include <ctime>

enum LIMITS {
	COLUMNS = 32,
	LINES = 32
};



int main() {

	srand((unsigned)time(NULL));

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