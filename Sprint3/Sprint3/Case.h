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

 // Représente une case de la grille
struct Case {
	unsigned content; // content, le contenu de la case
	STATE state; // state, l'état de la case
};

/**
*	@brief montre le contenu de l'élément de la case en fonction de son état
*	@param[in] elementType, le contenu de l'élément
*	@return le contenu de l'élément en fonction de son état
*/
char showElement(Case elementType);

#endif // !_CASE_