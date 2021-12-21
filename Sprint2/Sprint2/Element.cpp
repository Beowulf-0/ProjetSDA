#include "Element.h"

/*
*	@brief affiche un caract�re en fonction du type de l'�l�ment
*	@param[in] elementType, le type de l'�l�ment
*	@return le type de l'�l�ment sous forme de char
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

