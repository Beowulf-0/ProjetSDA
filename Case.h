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

 // Represente une case de la grille
struct Case {
	unsigned content; // content, le contenu de la case
	STATE state; // state, l'etat de la case
};

/**
*	@brief montre le contenu de l'element de la case en fonction de son etat
*	@param[in] elementType, le contenu de l'element
*	@return le contenu de l'element en fonction de son etat
*/
char showElement(Case elementType);

#endif // !_CASE_