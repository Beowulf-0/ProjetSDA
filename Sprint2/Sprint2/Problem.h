#ifndef _PROBLEM_
#define _PROBLEM_

#include "Mine.h"

/**
 * @file Problem.h
 * @author WAHADA Mehdi & ALI Mehdi
 * @version 1 28/12/2021
 * @brief Le problème du démineur
 */

// représente le problème du démineur
struct Problem {
	unsigned lineNumber; // lineNumber, le nombre de lignes
	unsigned columnNumber; //columnNumber, le nombre de colonnes
	unsigned mineNumber; //mineNumber, le nombre de mines
	Mine *mineLoc; // mineLoc, le tableau de mines
};

/**
*	@brief affecte les valeurs des variables au problème 
*	(et alloue dynamiquement le tableau de mines)
*	@param[in,out] pb, le problème
*	@param[in] lines, le nombre de lignes
*	@param[in] column, le nombre de colonnes
*	@param[in] mines, le nombre de mines
*/
void defineProblem(Problem *pb, unsigned lines, unsigned column, unsigned mines);

/**
*	@brief mélange un tableau de mines
*	@param[in,out] p, le problème
*	@param[in,out] tab, le tableau de mines
*/
void shuffleArray(Problem *p, unsigned int *tab);

/**
*	@brief Génère des mines à des coordonnées aléatoires valides
*	@param[in,out] pb, le problème
*	@param[in,out] mineList, le tableau de mines
*/
void generateMine(Problem *pb, Mine *mineList);

/**
*	@brief affecte les valeurs des variables au problème
*	(et alloue dynamiquement le tableau de mines)
*/
void createProblem();

#endif // !_PROBLEM_

