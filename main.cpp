#include <iostream>


/*	@brief représente un problème dans une partie de démineur 
*
*
*/
struct Probleme {
	unsigned int nbLignes;
	unsigned int nbColonnes;
	unsigned int nbMines;
};

struct Historique {
	unsigned int nbCoups;
};

struct Grille {
	Probleme probleme;
};

/*	@brief Crée un problème
*	@param[in-out] p, le problème
*/
void createProblem(Probleme& p);

int main() {

	char commande;
	switch (commande){
	case '1':
		//createProblem();

	case '2':
		//createGrid();

	case '3':
		//

	case '4':
		//

	case '5':
		//
	}
}

void createProblem(Probleme& p) {
	std::cin >> p.nbLignes >> p.nbColonnes >> p.nbMines;
}
