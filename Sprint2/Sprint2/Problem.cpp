#include "Problem.h"
#include <random>
#include <iostream>

/*
*	@brief crée un problème
*	@param[in,out] pb, le problème
*	@param[in] lines, le nombre de lignes
*	@param[in] column, le nombre de colonnes
*	@param[in] mines, le nombre de mines
*/
void defineProblem(Problem *pb, unsigned lines, unsigned column, unsigned mines) {
	pb->lineNumber = lines;
	pb->columnNumber = column;
	pb->mineNumber = mines;
	pb->mineLoc = new Mine[pb->mineNumber];
}

/*
*	@brief mélange un tableau de positions de mines en fonction de sa taille
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

/*
*	@brief génère des mines sur des positions aléatoires
*	@param[in,out] pb, le problème
*	@param[in,out] mineList, le tableau de mines
*/
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

/*
*	@brief crée un problème
*	@param[in,out] pb, le problème
*	@param[in] lines, le nombre de lignes
*	@param[in] column, le nombre de colonnes
*	@param[in] mines, le nombre de mines
*/
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

	std::cout << problem.lineNumber << " " << problem.columnNumber
		<< " " << problem.mineNumber << " ";
	for (unsigned i = 0; i < problem.mineNumber; i++) {
		std::cout << problem.mineLoc[i] << " ";
	}

	std::cout << "\n";

	//delete memory
	delete[] problem.mineLoc;
}