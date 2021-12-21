#ifndef _ELEMENT_

enum ELEMENTS {
	VOID = 0,
	BOMB = 10,
	VIEWED = 20,
	MARKED = 30
};

/*
*	@brief affiche un caract�re en fonction du type de l'�l�ment 
*	@param[in] elementType, le type de l'�l�ment
*	@return le type de l'�l�ment sous forme de char
*/
char showElement(unsigned elementType);

#endif // !_ELEMENT_

