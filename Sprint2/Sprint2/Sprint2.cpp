#include <iostream>
#include <time.h>
#include <cassert>
#include <random>

typedef char *Coup;
/**
*	@brief représente un problème dans une partie de démineur
*/
struct Probleme {
	unsigned int nbLignes;
	unsigned int nbColonnes;
	unsigned int nbMines;
	unsigned int *tabMines;
};

struct Historique {
	unsigned int nbCoups;
	Coup *coups;
};

struct Grille {
	Probleme probleme;
	unsigned int** tabGrille;
	Historique histo;
};

/**
*	@brief Crée un problème
*	@param[in-out] p, le problème
*/
void createProblem(Probleme& p);

/**	@brief Génère des mines sur des positions aléatoires
*	@param[in-out] p, le problème
*	@param[in-out] mines, le tableau de mines
*/
void genererMines(Probleme& p, unsigned int *mines);

/**	@brief Créer une grille à partir d'un problème et de l'historique de coups
*	@param[in-out] g, la grille
*/
void createGrid(Grille& g);

void printGrid(const Grille& g);

int main() {
	srand((unsigned int)time(NULL));

	Probleme p;
	Grille g;

	int commande;

	while (true) {
		std::cin >> commande;
		switch (commande) {
		case 1:
			createProblem(p);
			break;
		case 2:
			createGrid(g);
			break;

		case 5:
			//
			break;
		case 6:
			return 0;
			break;
		}
	}

}

void createProblem(Probleme& p) {

	std::cin >> p.nbLignes >> p.nbColonnes >> p.nbMines;

	p.tabMines = new unsigned int[p.nbMines];

	genererMines(p, p.tabMines);

	std::cout << p.nbLignes << " " << p.nbColonnes << " " << p.nbMines;

	for (unsigned int i = 0; i < p.nbMines; i++) {
		std::cout << " " << p.tabMines[i];
	}
	std::cout << std::endl;
}

//pas obligé de faire une seule ligne avec toutes les commandes, fait des boucles.
//pour extraire les sous chaines, voir strncpy et atoi (convertir)

/**	@brief réalise une grille à partir du nombre de lignes, de colonnes, de mines, des positions des mines et de l'historique de coups
*	@param[in-out] g, la grille créé
*
*/
void createGrid(Grille& g) {
	unsigned int *tMines = g.probleme.tabMines;

	char tmp[10];
	char coup[10];
	int position;
	unsigned int lignes = position / g.probleme.nbLignes;
	unsigned int colonnes = position % g.probleme.nbColonnes;
	std::cin >> g.probleme.nbLignes >> g.probleme.nbColonnes >> g.probleme.nbMines;

	tMines = new unsigned int[g.probleme.nbMines];

	for (unsigned int m = 0; m < g.probleme.nbMines; m++) {
		std::cin >> tMines[m];
	}

	std::cin >> g.histo.nbCoups;

	g.histo.coups = new Coup[g.histo.nbCoups];
	g.tabGrille = new unsigned int*[g.probleme.nbLignes];

	for (unsigned int grL = 0; grL < g.probleme.nbLignes; grL++) {
		g.tabGrille[grL] = new unsigned int[g.probleme.nbColonnes];
	}
	
	for (unsigned int c = 0; c < g.histo.nbCoups; c++) {
		std::cin >> coup;
		strcpy(g.histo.coups[c], coup);
		strncpy(tmp, coup + 1, strlen(coup) - 1);
		position = atoi(tmp);
		g.tabGrille[lignes][colonnes] = tMines[c];
	}

	std::cout << g.probleme.nbLignes << " " << g.probleme.nbColonnes << " " << g.probleme.nbMines << " ";
	for (unsigned int i = 0; i < g.probleme.nbMines; i++) {
		std::cout << tMines[i] << " ";
	}

	std::cout << g.histo.nbCoups << " ";

	for (unsigned int j = 0; j < g.histo.nbCoups; j++) {
		std::cout << g.histo.coups[j] << " ";
	}

	std::cout << std::endl;

	printGrid(g);

	for (unsigned int k = 0; k < lignes; k++) {
		delete[] g.tabGrille[k];
	}
	delete[] tMines;
	
}


//vérifier comment convertir un entier en char.
//afficherGrille : affiche les ___ / || suivi du contenu des variables (à actualiser à chaque coup) / convertir un chiffre en char. / Si c'est D : 
void printGrid(const Grille& g) {
	std::cout << g.probleme.nbLignes << " " << g.probleme.nbColonnes;
	std::cout << std::endl;
	for (unsigned int i = 0; i < g.probleme.nbColonnes; i++) {
		for (unsigned int j = 0; j < g.probleme.nbLignes; j++) {
			if (j == 0) std::cout << "| " << " |";
			else std::cout << "  |";
		}
		std::cout << std::endl;
	}
}

void genererMines(Probleme& p, unsigned int *mines) {
	for (unsigned int m = 0; m < p.nbMines; m++) {
		unsigned int limitePos = p.nbColonnes * p.nbLignes;
		mines[m] = std::rand() % limitePos;
	}
}

void tests() {

}