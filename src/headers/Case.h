#ifndef _CASE_
#define _CASE_

#include "State.h"
#include "Content.h"

/**
 * @file Case.h
 * @author WAHADA Mehdi & ALI Mehdi
 * @version 1 28/12/2021
 * @brief Case de la grille
 */

 // Repr�sente une case de la grille
struct Case {
	unsigned content; // content, le contenu de la case
	STATE state; // state, l'�tat de la case
};

/**
*	@brief montre le contenu de l'�l�ment de la case en fonction de son �tat
*	@param[in] elementType, le contenu de l'�l�ment
*	@return le contenu de l'�l�ment en fonction de son �tat
*/
char showElement(Case elementType);

#include "../components/Case.cpp"
#endif // !_CASE_