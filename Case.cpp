#include "Case.h"

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