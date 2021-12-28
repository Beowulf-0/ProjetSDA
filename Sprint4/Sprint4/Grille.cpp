#include "Grille.h"
#include <iostream>

void createGrille() {
	unsigned line, column, nbrMine, nbrStroke;
	Grille gr{};

	std::cin >> line >> column >> nbrMine;

	defineProblem(&gr.pb, line, column, nbrMine);
	generateGrid(&gr);
	setMines(&gr);

	fillGrid(&gr);

	//Stroke System
	defineHisto(&gr.histo);
	setStroke(&gr);
	executeStroke(&gr);

	printGrid(&gr);

	//delete memory
	for (unsigned i = 0; i < line; i++) {
		delete[] gr.tab[i];
	}
	delete[] gr.tab;
	delete[] gr.histo.strokes;
	delete[] gr.pb.mineLoc;
}


void placeMines(Grille *gr) {
	for (unsigned m = 0; m < gr->pb.mineNumber; m++) {
		Mine mine = gr->pb.mineLoc[m];
		unsigned line = mine / gr->pb.columnNumber,
			column = mine % gr->pb.columnNumber;
		if (validCase(gr, line, column)) gr->tab[line][column].content = CONTENT::MINE;
	}
}


void setMines(Grille *gr) {
	for (unsigned m = 0; m < gr->pb.mineNumber; m++) {
		Mine mineLoc;

		std::cin >> mineLoc;
		gr->pb.mineLoc[m] = mineLoc;
	}
}


void demask(Grille *gr, unsigned int x, unsigned int y) {
	enum {
		TESTS_TO_DO = 8
	};
	unsigned int toTest[TESTS_TO_DO][2] =
	{
			{x + 0, y + 1},
			{x + 0, y - 1},
			{x + 1, y + 0},
			{x + 1, y + 1},
			{x + 1, y - 1},
			{x - 1, y + 0},
			{x - 1, y + 1},
			{x - 1, y - 1},
	};

	Case *c = &(gr->tab[x][y]);
	c->state = STATE::SHOWED;

	if (c->content != CONTENT::VOID) return;

	for (auto &tElm : toTest) {
		if (validCase(gr, tElm[0], tElm[1]) && (gr->tab[tElm[0]][tElm[1]]).state == STATE::HIDED) {
			demask(gr, tElm[0], tElm[1]);
		}
	}
}

unsigned minesNearby(Grille *gr, unsigned int x, unsigned int y) {
	//Si c'est une mine, ça dégage ;)
	if (detectedMines(gr, x, y)) return 0;

	unsigned int mineCount = 0;
	enum {
		TESTS_TO_DO = 8
	};
	unsigned int toTest[TESTS_TO_DO][2] =
	{
			{x + 0, y + 1},
			{x + 0, y - 1},
			{x + 1, y + 0},
			{x + 1, y + 1},
			{x + 1, y - 1},
			{x - 1, y + 0},
			{x - 1, y + 1},
			{x - 1, y - 1},
	};

	//Auto && testing element permet de boucler les éléments du tableau de toTest
	// donc testingElement aura au début la première valeur de toTest puis la deuxième... etc
	for (auto &testingElement : toTest) {
		if (validCase(gr, testingElement[0], testingElement[1])
			&& detectedMines(gr, testingElement[0], testingElement[1]))
			mineCount++;
	}
	return mineCount;
}

/**
*	@brief vérifie si une case contient une mine
*	@param[in] gr, la grille
*	@param[in] x, l'abscisse
*	@param[in] y, l'ordonnée
*	@return true si le contenu de la case est une mine, sinon false
*/
bool detectedMines(Grille *gr, unsigned int x, unsigned int y) { //adjacente : g/h : h/b : diagonale
	return gr->tab[x][y].content == CONTENT::MINE;
}

/**
*	@brief vérifie si une case est valide
*	@param[in] gr, la grille
*	@param[in] x, l'abscisse
*	@param[in] y, l'ordonnée
*	@return true si x/y sont inférieurs au nombre de lignes / colonnes
*	et supérieurs ou égales à 0, sinon false
*/
bool validCase(Grille *gr, unsigned int x, unsigned int y) {
	return (x >= 0 && x < gr->pb.lineNumber) && (y >= 0 && y < gr->pb.columnNumber);
}

/**
*	@brief rentre les coups de l'historique
*	@param[in,out] gr, la grille
*/
void setStroke(Grille *gr) {
	for (unsigned int str = 0; str < gr->histo.nbrStrokes; str++) {
		char stroke;
		unsigned int pos;
		std::cin >> stroke >> pos;
		gr->histo.strokes[str].letter = stroke;
		gr->histo.strokes[str].pos = pos;
	}
}

/**
*	@brief Analyse chaque coup de l'historique. Si la lettre du coup est un D, démasque la case ciblée et si c'est un M, la marque.
*	@param[in,out] gr, la grille
*/
void executeStroke(Grille *gr) {
	for (unsigned i = 0; i < gr->histo.nbrStrokes; i++) {
		unsigned line = gr->histo.strokes[i].pos / gr->pb.columnNumber,
			column = gr->histo.strokes[i].pos % gr->pb.columnNumber;

		switch (gr->histo.strokes[i].letter) {
		case 'M':
			if (validCase(gr, line, column))
				gr->tab[line][column].state = MARKED;
			break;
		case 'D':
			if (validCase(gr, line, column)) demask(gr, line, column);
			break;
		default:
			//Throw Error ?
			break;
		}
	}
}

/**
*	@brief Affiche la grille de démineur
*	@param[in] g, la grille
*/
void printGrid(const Grille *g) {
	unsigned lines = g->pb.lineNumber,
		columns = g->pb.columnNumber;

	std::cout << lines << " " << columns << "\n";
	for (unsigned int i = 0; i < lines; i++) {
		for (unsigned _ = 0; _ < columns; _++) {
			std::cout << " ___";
		}
		std::cout << "\n";
		for (unsigned int j = 0; j < columns; j++) {
			std::cout << ((j == 0) ? "| " : " ")
				<< showElement(g->tab[i][j])
				<< " |";
		}
		std::cout << "\n";
	}
	for (unsigned _ = 0; _ < columns; _++) {
		std::cout << " ___";
	}
	std::cout << "\n";
}

/**
*	@brief remplit la grille avec les mines
*	@param[in,out] gr, la grille
*/
void fillGrid(Grille *gr) {
	unsigned lines = gr->pb.lineNumber,
		columns = gr->pb.columnNumber;

	placeMines(gr);

	for (unsigned i = 0; i < lines; i++) {
		for (unsigned j = 0; j < columns; j++) {
			unsigned readableNum = i * lines + j;
			if (gr->tab[i][j].content != CONTENT::MINE) gr->tab[i][j].content = minesNearby(gr, i, j);
			gr->tab[i][j].state = STATE::HIDED;
		}
	}
}

/**
*	@brief Alloue dynamiquement les colonnes de la grille
*	@param[in,out] gr, la grille
*/
void generateGrid(Grille *gr) {
	gr->tab = new Case *[gr->pb.lineNumber];
	for (unsigned i = 0; i < gr->pb.lineNumber; i++) {
		gr->tab[i] = new Case[gr->pb.columnNumber];
	}
}

/**
*	@brief vérifie si la partie est perdue
*	@param[in] gr, la grille
*	@return vrai si une case vide est démasqué ou si une case minée est marquée, sinon false.
*/
bool isLost(const Grille *gr) {
	unsigned lines = gr->pb.lineNumber,
		columns = gr->pb.columnNumber;
	for (unsigned int i = 0; i < lines; i++) {
		for (unsigned int j = 0; i < columns; j++) {
			if (gr->tab[i][j].content == CONTENT::MINE
				&& gr->tab[i][j].state == STATE::SHOWED) return true;
			else if (gr->tab[i][j].state == STATE::MARKED
				&& gr->tab[i][j].state == STATE::MARKED) return true;
		}
	}
	return false;
}

void gameLost() {
	unsigned line, column, nbrMine, nbrStroke;
	Grille gr{};

	std::cin >> line >> column >> nbrMine;

	defineProblem(&gr.pb, line, column, nbrMine);
	generateGrid(&gr);
	setMines(&gr);

	fillGrid(&gr);

	//Stroke System
	defineHisto(&gr.histo);
	setStroke(&gr);
	executeStroke(&gr);
	
	if (isLost(&gr)) {
		std::cout << "game lost";
	}
	else {
		std::cout << "game not lost";
	}

	//delete memory
	for (unsigned i = 0; i < line; i++) {
		delete[] gr.tab[i];
	}
	delete[] gr.tab;
	delete[] gr.histo.strokes;
	delete[] gr.pb.mineLoc;
}