#ifndef _PROBLEM_
#define _PROBLEM_

#include "Mine.h"

/**
 * @file Problem.h
 * @author WAHADA Mehdi & ALI Mehdi
 * @version 1 28/12/2021
 * @brief Le probleme du demineur
 */

// represente le probleme du demineur
struct Problem {
    unsigned lineNumber; // lineNumber, le nombre de lignes
    unsigned columnNumber; //columnNumber, le nombre de colonnes
    unsigned mineNumber; //mineNumber, le nombre de mines
    Mine *mineLoc; // mineLoc, le tableau de mines
};

/**
*	@brief affecte les valeurs des variables au probleme
*	(et alloue dynamiquement le tableau de mines)
*	@param[in,out] pb, le probleme
*	@param[in] lines, le nombre de lignes
*	@param[in] column, le nombre de colonnes
*	@param[in] mines, le nombre de mines
*/
void defineProblem(Problem *pb, unsigned lines, unsigned column, unsigned mines);

/**
*	@brief melange un tableau de mines
*	@param[in,out] p, le probleme
*	@param[in,out] tab, le tableau de mines
*/
void shuffleArray(Problem *p, unsigned int *tab);

/**
*	@brief Genere des mines e des coordonnees aleatoires valides
*	@param[in,out] pb, le probleme
*	@param[in,out] mineList, le tableau de mines
*/
void generateMine(Problem pb, Mine *mineList);

/**
  * @brief affiche les caractéristiques du problème
  * @param[in] pb, le probleme
 */
void showProblem(Problem &pb);

/**
 * @brief supprime l'allocation dynamique attribué au problème
 *	@param[in] pb, le probleme
 */
void deleteProblem(Problem &pb);

/**
*	@brief affecte les valeurs des variables au probleme
*	(et alloue dynamiquement le tableau de mines)
*/
void createProblem();


#endif // !_PROBLEM_