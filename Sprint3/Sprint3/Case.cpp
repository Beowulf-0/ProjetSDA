#include "Case.h"

/**
*	@brief montre le contenu de l'élément de la case en fonction de son état
*	@param[in] elementType, le contenu de l'élément
*	@return le contenu de l'élément en fonction de son état
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