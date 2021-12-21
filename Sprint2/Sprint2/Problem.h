#ifndef _PROBLEM_
#define _PROBLEM_

#include "Mine.h"

/*
*	@brief représente un problème
*/
struct Problem {
	unsigned lineNumber; // lineNumber, le nombre de lignes
	unsigned columnNumber; // columnNumber, le nombre de colonnes
	unsigned mineNumber; // mineNumber, le nombre de mines
	Mine *mineLoc; // mineLoc, le tableau de mines
};


/*
*	@brief crée un problème
*	@param[in,out] pb, le problème
*	@param[in] lines, le nombre de lignes
*	@param[in] column, le nombre de colonnes
*	@param[in] mines, le nombre de mines
*/
void defineProblem(Problem *pb, unsigned lines, unsigned column, unsigned mines);

/*
*	@brief génère des mines sur des positions aléatoires
*	@param[in,out] pb, le problème
*	@param[in,out] mineList, le tableau de mines
*/
void generateMine(Problem *pb, Mine *mineList);

/*
*	@brief mélange un tableau de positions de mines en fonction de sa taille
*	@param[in,out] p, le problème
*	@param[in,out] tab, le tableau de mines
*/
void shuffleArray(Problem *p, unsigned int *tab);

/*
*	@brief crée un problème de démineur
*/
void createProblem();

#endif // !_PROBLEM_

