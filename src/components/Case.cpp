#include "../headers/Case.h"

/**
*	@brief montre le contenu de l'�l�ment de la case en fonction de son �tat
*	@param[in] elementType, le contenu de l'�l�ment
*	@return le contenu de l'�l�ment en fonction de son �tat
*/
char showElement(Case elementType) {
	switch (elementType.state) {
	case STATE::SHOWED:
		if (elementType.content == CONTENT::VOID) return ' ';
		else if (elementType.content != CONTENT::MINE) return (char)(48 + elementType.content);
		else return 'M';
	case STATE::HIDED:
		return '.';
	case STATE::MARKED:
		return 'x';
	default:
		return (char)(48 + elementType.content);
	}
}