/**
 * @name MineSweeper
 * @brief D�mineur simple sans interface graphique.
 *
 * @authors BadiiiX & Beowulf
 * @version 0.0.1
 */

#include <iostream>
#include <random>
#include <string>
#include <ctime>
#include "Item.h"
#include "File.h"

enum LIMITS {
	COLUMNS = 32,
	LINES = 32
};
//tant que c'est diff�rent de 0, on d�masque la case mais pas les voisines, sinon si c'est �gal � z�ro, on d�masque la case aux alentours.

enum CONTENT {
	MINE = 10, //Here, 10 bc we cannot have more than 8.
	VOID = 0
};

//type �num�r� pour les lettres
typedef unsigned Mine;

struct Stroke {
	char letter;
	unsigned int pos;
};

struct Historique {
	unsigned nbrStrokes;
	Stroke *strokes;
};

struct Problem {
	unsigned lineNumber;
	unsigned columnNumber;
	unsigned mineNumber;
	Mine *mineLoc;
};

struct Grille {
	Problem pb;
	Case **tab;
	Historique histo;
};

void shuffleArray(Problem *p, unsigned int *tab);

void generateMine(Problem *pb, Mine *mineList);

void defineProblem(Problem *pb, unsigned lines, unsigned column, unsigned mines);

void generateGrid(Grille *gr);

void executeStroke(Grille *gr);

void unmaskMines(Grille *gr, unsigned int x, unsigned int y);


bool validCase(Grille *gr, unsigned int x, unsigned int y) {
	return (x >= 0 && x < gr->pb.lineNumber) && (y >= 0 && y < gr->pb.columnNumber);
}

void shuffleArray(Problem *p, unsigned int *tab) {
	unsigned int maxValue = p->lineNumber * p->columnNumber;
	unsigned int ech;
	for (unsigned int i = 0; i < p->mineNumber; i++) {
		unsigned j = std::rand() % maxValue;
		ech = tab[j];
		tab[j] = tab[i];
		tab[i] = ech;
	}
}


void defineProblem(Problem *pb, unsigned lines, unsigned column, unsigned mines) {
	pb->lineNumber = lines;
	pb->columnNumber = column;
	pb->mineNumber = mines;
	pb->mineLoc = new Mine[pb->mineNumber];
}

void defineHisto(Historique *hist) {
	unsigned nbrStroke;
	std::cin >> nbrStroke;
	hist->nbrStrokes = nbrStroke;
	hist->strokes = new Stroke[hist->nbrStrokes];
}

// les nombres g�n�r�s doivent �tre les bons : cr�er un tableau de taille 0 � n et l'initialiser, utiliser l'algo pour m�langer et prendre les n premi�res valeurs
void generateMine(Problem *pb, Mine *mineList) {
	//TODO: Security about Problem
	unsigned int maxValue = pb->columnNumber * pb->lineNumber;
	unsigned *tab;
	tab = new unsigned int[maxValue];
	for (unsigned i = 0; i < maxValue; i++) {
		tab[i] = i;
	}

	shuffleArray(pb, tab);

	for (unsigned m = 0; m < pb->mineNumber; m++) {
		mineList[m] = tab[m];
	}
	delete[] tab;
}

void setMines(Grille *gr) {
	for (unsigned m = 0; m < gr->pb.mineNumber; m++) {
		Mine mineLoc;

		std::cin >> mineLoc;
		gr->pb.mineLoc[m] = mineLoc;
	}
}

void placeMines(Grille *gr) {
	for (unsigned m = 0; m < gr->pb.mineNumber; m++) {
		Mine mine = gr->pb.mineLoc[m];
		unsigned line = mine / gr->pb.columnNumber,
			column = mine % gr->pb.columnNumber;
		if (validCase(gr, line, column)) gr->tab[line][column].content = CONTENT::MINE;
	}
}

bool detectedMines(Grille *gr, unsigned int x, unsigned int y) { //adjacente : g/h : h/b : diagonale
	return gr->tab[x][y].content == CONTENT::MINE;
}

/**
*	@brief Incr�mente les cases � proximit�s de mines
*	@param[in,out] gr, la grille
*	@param[in] x, l'abscisse x de la grille
*	@param[in] y, l'ordonn�e y de la grille
*/
unsigned minesNearby(Grille *gr, unsigned int x, unsigned int y) {
	//Si c'est une mine, �a d�gage ;)
	if (detectedMines(gr, x, y)) return 0;

	unsigned int mineCount = 0;
	enum {
		TESTS_TO_DO = 8
	};
	unsigned int toTest[TESTS_TO_DO][2] =
	{
			{x,     y + 1},
			{x,     y - 1},
			{x + 1, y + 0},
			{x + 1, y + 1},
			{x + 1, y - 1},
			{x - 1, y + 0},
			{x - 1, y + 1},
			{x - 1, y - 1},
	};

	//Auto && testing element permet de boucler les �l�ments du tableau de toTest
	// donc testingElement aura au d�but la premi�re valeur de toTest puis la deuxi�me... etc
	for (auto &testingElement : toTest) {
		if (validCase(gr, testingElement[0], testingElement[1])
			&& detectedMines(gr, testingElement[0], testingElement[1]))
			mineCount++;
	}
	return mineCount;
}

char showElement(Case elementType) {
	switch (elementType.state) {
	case STATE::SHOWED:
		if (elementType.content != CONTENT::MINE) return (char)(48 + elementType.content);
		else return 'M';
	case STATE::HIDED:
		return '.';
	case STATE::MARKED:
		return 'x';
	default:
		return (char)(48 + elementType.content);
	}
}

void setStroke(Grille *gr) {
	for (unsigned int str = 0; str < gr->histo.nbrStrokes; str++) {
		char stroke;
		unsigned int pos;
		std::cin >> stroke >> pos;
		gr->histo.strokes[str].letter = stroke;
		gr->histo.strokes[str].pos = pos;
	}
}

void executeStroke(Grille *gr) {
	for (unsigned i = 0; i < gr->histo.nbrStrokes; i++) {
		unsigned line = gr->histo.strokes[i].pos / gr->pb.columnNumber,
			column = gr->histo.strokes[i].pos % gr->pb.columnNumber;

		switch (gr->histo.strokes[i].letter) {
		case 'M':
			if (validCase(gr, line, column))
				gr->tab[line][column].state = STATE::MARKED;
			break;
		case 'D':
			if (validCase(gr, line, column)) continue;
			//FUNCTION TO DEMASK
			break;
		default:
			//Throw Error ?
			break;
		}
	}
}

void generateGrid(Grille *gr) {
	gr->tab = new Case *[gr->pb.lineNumber];
	for (unsigned i = 0; i < gr->pb.lineNumber; i++) {
		gr->tab[i] = new Case[gr->pb.columnNumber];
	}
}

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
			//Todo, create function to show elemnt about his value
			std::cout << ((j == 0) ? "| " : " ")
				<< showElement(g->tab[i][j])
				<< " |";
		}
		std::cout << "\n";
	}
	for (unsigned _ = 0; _ < columns; _++) {
		std::cout << " ___";
	}
}

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

void createProblem() {
	unsigned line, column, mines;
	Problem problem{};

	std::cin >> line >> column >> mines;

	//Generate mines
	problem.lineNumber = line;
	problem.columnNumber = column;
	problem.mineNumber = mines;
	problem.mineLoc = new Mine[problem.mineNumber];
	generateMine(&problem, problem.mineLoc);

	std::cout << problem.lineNumber << " " << problem.columnNumber
		<< " " << problem.mineNumber << " ";
	for (unsigned i = 0; i < problem.mineNumber; i++) {
		std::cout << problem.mineLoc[i] << " ";
	}

	std::cout << "\n";

	//delete memory
	delete[] problem.mineLoc;
}

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

int main() {

	srand((unsigned)time(NULL));

	int cmd;
	bool loop = true;

	while (loop) {
		//WARNING: If cmd get a string, loop can be infinite ;(
		std::cin >> cmd;
		switch ((int)cmd) {
		case 1:
			createProblem();
			break;

		case 2:
			createGrille();
			break;

		case 3:
			break;

		case 4:
			gameWon();
			break;

		case 5:
			break;

		case 6:
			loop = false;

		default:
			std::cout << "Commande inconnue";
			break;

		}
	}
}

/*
*	@brief D�masque une case. Si elle est vide, d�masque les autres aux alentours, sinon n'affiche que la case cibl�.
*	@param[in,out] gr, la grille
*	@param[in] x, l'abscisse
*	@param[in] y, l'ordonn�e
*/
void unmaskMines(Grille *gr, unsigned int x, unsigned int y) {
	enum {
		TESTS_TO_DO = 8
	};
	unsigned int toTest[TESTS_TO_DO][2] =
	{
			{x,     y + 1},
			{x,     y - 1},
			{x + 1, y + 0},
			{x + 1, y + 1},
			{x + 1, y - 1},
			{x - 1, y + 0},
			{x - 1, y + 1},
			{x - 1, y - 1},
	};

	File f;
	Case c = gr->tab[x][y];
	initialiser(f);
	entrer(f, c);
	while (!estVide(f)) {
		Case el;
		do {
			el = sortir(f);
		} while (el.state == STATE::SHOWED);
		el.state = STATE::SHOWED;

		for (auto &testingElement : toTest) {
			if (validCase(gr, testingElement[0], testingElement[1])) {
				entrer(f, gr->tab[testingElement[0]][testingElement[1]]);
			}
		}
	}
}

bool isLost(Grille *gr) {
	unsigned lines = gr->pb.lineNumber, column = gr->pb.columnNumber;
	for (unsigned int i = 0; i < lines; i++) {
		for (unsigned int j = 0; i < column; j++) {
			if (gr->tab[i][j].content == CONTENT::MINE && gr->tab[i][j].state == STATE::SHOWED) {
				return true;
			}
		}
	}
}

void gameWon() {
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

	for (unsigned i = 0; i < line; i++) {
		delete[] gr.tab[i];
	}
	delete[] gr.tab;
	delete[] gr.histo.strokes;
	delete[] gr.pb.mineLoc;
}