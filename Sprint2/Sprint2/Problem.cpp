#include "Problem.h"
#include <random>
#include <iostream>

/**
*	@brief Génère des mines à des coordonnées aléatoires valides
*	@param[in,out] pb, le problème
*	@param[in,out] mineList, le tableau de mines
*/
void defineProblem(Problem *pb, unsigned lines, unsigned column, unsigned mines) {
	pb->lineNumber = lines;
	pb->columnNumber = column;
	pb->mineNumber = mines;
	pb->mineLoc = new Mine[pb->mineNumber];
}

/**
*	@brief mélange un tableau de mines
*	@param[in,out] p, le problème
*	@param[in,out] tab, le tableau de mines
*/
void shuffleArray(Problem *p, unsigned int *tab) {
	unsigned int maxValue = p->lineNumber * p->columnNumber;
	unsigned int ech;
	for (unsigned int i = 0; i < p->mineNumber; i++) {
		unsigned j = std::rand() % maxValue;
		ech = tab[j];
		tab[j] = tab[i];
		tab[i] = ech;
	}
}

void generateMine(Problem *pb, Mine *mineList) {
	//TODO: Security about Problem
	unsigned int maxValue = pb->columnNumber * pb->lineNumber;
	unsigned *tab;
	tab = new unsigned int[maxValue];
	for (unsigned i = 0; i < maxValue; i++) {
		tab[i] = i;
	}

	shuffleArray(pb, tab);

	for (unsigned m = 0; m < pb->mineNumber; m++) {
		mineList[m] = tab[m];
	}
	delete[] tab;
}

/**
*	@brief affecte les valeurs des variables au problème
*	(et alloue dynamiquement le tableau de mines)
*/
void createProblem() {
	unsigned line, column, mines;
	Problem problem{};

	std::cin >> line >> column >> mines;

	//Generate mines
	defineProblem(&problem, line, column, mines);
	generateMine(&problem, problem.mineLoc);

	std::cout << problem.lineNumber << " " << problem.columnNumber
		<< " " << problem.mineNumber << " ";
	for (unsigned i = 0; i < problem.mineNumber; i++) {
		std::cout << problem.mineLoc[i] << " ";
	}

	std::cout << "\n";

	//delete memory
	delete[] problem.mineLoc;
}
