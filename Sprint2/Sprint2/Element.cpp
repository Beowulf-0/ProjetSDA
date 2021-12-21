#include "Element.h"

/*
*	@brief affiche un caractère en fonction du type de l'élément
*	@param[in] elementType, le type de l'élément
*	@return le type de l'élément sous forme de char
*/
char showElement(unsigned elementType) {
	switch (elementType) {
	case ELEMENTS::VIEWED:
		return ' ';
	case ELEMENTS::BOMB:
	case ELEMENTS::VOID:
		return '.';
	case ELEMENTS::MARKED:
		return 'x';
	default:
		return (char)elementType;
	}
}

