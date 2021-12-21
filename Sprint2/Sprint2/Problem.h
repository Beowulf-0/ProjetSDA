#ifndef _PROBLEM_
#define _PROBLEM_

#include "Mine.h"

/*
*	@brief repr�sente un probl�me
*/
struct Problem {
	unsigned lineNumber; // lineNumber, le nombre de lignes
	unsigned columnNumber; // columnNumber, le nombre de colonnes
	unsigned mineNumber; // mineNumber, le nombre de mines
	Mine *mineLoc; // mineLoc, le tableau de mines
};


/*
*	@brief cr�e un probl�me
*	@param[in,out] pb, le probl�me
*	@param[in] lines, le nombre de lignes
*	@param[in] column, le nombre de colonnes
*	@param[in] mines, le nombre de mines
*/
void defineProblem(Problem *pb, unsigned lines, unsigned column, unsigned mines);

/*
*	@brief g�n�re des mines sur des positions al�atoires
*	@param[in,out] pb, le probl�me
*	@param[in,out] mineList, le tableau de mines
*/
void generateMine(Problem *pb, Mine *mineList);

/*
*	@brief m�lange un tableau de positions de mines en fonction de sa taille
*	@param[in,out] p, le probl�me
*	@param[in,out] tab, le tableau de mines
*/
void shuffleArray(Problem *p, unsigned int *tab);

/*
*	@brief cr�e un probl�me de d�mineur
*/
void createProblem();

#endif // !_PROBLEM_

