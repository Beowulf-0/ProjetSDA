#ifndef _ELEMENT_

enum ELEMENTS {
	VOID = 0,
	BOMB = 10,
	VIEWED = 20,
	MARKED = 30
};

/*
*	@brief affiche un caractère en fonction du type de l'élément 
*	@param[in] elementType, le type de l'élément
*	@return le type de l'élément sous forme de char
*/
char showElement(unsigned elementType);

#endif // !_ELEMENT_

