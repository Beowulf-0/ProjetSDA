/**
 * @name MineSweeper
 * @brief Démineur simple sans interface graphique.
 *
 * @authors BadiiiX & Beowulf
 * @version 0.0.1
 */

#include <iostream>
#include <random>
#include <string>
#include <time.h>

enum LIMITS {
	COLUMNS = 32,
	LINES = 32
};
//tant que c'est différent de 0, on démasque la case mais pas les voisines, sinon si c'est égal à zéro, on démasque la case aux alentours. 
enum ELEMENTS {
	BOMB = 1,
	VOID = 0,
	VIEWED = -1
};
//type énuméré pour les lettres
typedef int Mine;

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
	unsigned **tab;
	Historique histo;
};
void shuffleArray(Problem *p, unsigned int *tab);

void generateMine(Problem *pb, Mine *mineList);

void defineProblem(Problem *pb, unsigned lines, unsigned column, unsigned mines);

void generateGrid(Grille *gr);

void setStroke(Grille &gr);

void defineProblem(Problem *pb, unsigned lines, unsigned column, unsigned mines) {
	pb->lineNumber = lines;
	pb->columnNumber = column;
	pb->mineNumber = mines;
	pb->mineLoc = new Mine[pb->mineNumber];
}

void defineHisto(Historique *hist, unsigned nbrStroke) {
	hist->nbrStrokes = nbrStroke;
	hist->strokes = new Stroke[hist->nbrStrokes];
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
// les nombres générés doivent être les bons : créer un tableau de taille 0 à n et l'initialiser, utiliser l'algo pour mélanger et prendre les n premières valeurs
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
		int mineLoc;
		std::cin >> mineLoc;
		gr->pb.mineLoc[m] = mineLoc;
	}
}
//fonction pour réveler les cases vides : 15 lignes et 20 lignes pour les autres.

bool validCase(Grille *gr, unsigned int x, unsigned int y) {
	return (x >= 0 && x < gr->pb.lineNumber) && (y >= 0 && y < gr->pb.columnNumber);
}

bool detectedMines(Grille *gr, unsigned int x, unsigned int y) { //adjacente : g/h : h/b : diagonale
	if (gr->tab[x][y] == ELEMENTS::BOMB) return true;
	else return false;
}

/**
*	@brief Incrémente les cases à proximités de mines
*	@param[in,out] gr, la grille
*	@param[in] x, l'abscisse x de la grille
*	@param[in] y, l'ordonnée y de la grille
*/
unsigned int minesNearby(Grille *gr, unsigned int x, unsigned int y) {
	unsigned int i = 0;
	if (validCase(gr, x + 1, y) == true) {
		if (detectedMines(gr, x + 1, y) == true) i++;
	}
	if (validCase(gr, x + 1, y + 1) == true) {
		if (detectedMines(gr, x + 1, y + 1) == true) i++;
	}
	if (validCase(gr, x, y + 1) == true) {
		if (detectedMines(gr, x, y + 1) == true) i++;
	}
	if (validCase(gr, x - 1, y + 1) == true) {
		if (detectedMines(gr, x - 1, y + 1) == true) i++;
	}
	if (validCase(gr, x - 1, y) == true) {
		if (detectedMines(gr, x - 1, y) == true) i++;
	}
	if (validCase(gr, x - 1, y - 1) == true) {
		if (detectedMines(gr, x - 1, y - 1) == true) i++;
	}
	if (validCase(gr, x, y - 1) == true) {
		if (detectedMines(gr, x, y - 1) == true) i++;
	}
	if (validCase(gr, x + 1, y - 1) == true) {
		if (detectedMines(gr, x + 1, y - 1) == true) i++;
	}
	return i;
}

//void checkStroke(Grille *gr, unsigned int x, unsigned int y) {
//	
//	for (unsigned int i = 0; i < gr->histo.nbrStrokes; i++) {
//		if (gr->histo.strokes[i].letter == 'D') {
//			//unmaskMines(unsigned int **tab)
//		}
//		else if (gr->histo.strokes[i].letter == 'M') {
//			
//		}
//	}
//}

void setStroke(Grille &gr) {
	for (unsigned int str = 0; str < gr.histo.nbrStrokes; str++) {
		char stroke;
		unsigned int pos;
		std::cin >> stroke >> pos;
		gr.histo.strokes[str].letter = stroke;
		gr.histo.strokes[str].pos = pos;
	}
}

void generateGrid(Grille *gr) {
	gr->tab = new unsigned *[gr->pb.lineNumber];
	for (unsigned i = 0; i < gr->pb.lineNumber; i++) {
		gr->tab[i] = new unsigned[gr->pb.columnNumber];
	}
}

void printGrid(const Grille *g) {
	unsigned lines = g->pb.lineNumber,
		columns = g->pb.columnNumber;

	std::cout << lines << " " << columns << std::endl;
	for (unsigned int i = 0; i < lines; i++) {
		for (unsigned _ = 0; _ < columns; _++) {
			std::cout << " ___";
		}
		std::cout << std::endl;
		for (unsigned int j = 0; j < columns; j++) {
			//Todo, create function to show elemnt about his value
			std::cout << ((j == 0) ? "| " : " ") << g->tab[i][j] << " |";
		}
		std::cout << std::endl;
	}
	for (unsigned _ = 0; _ < columns; _++) {
		std::cout << " ___";
	}
}

void fillGrid(Grille *g) {
	unsigned lines = g->pb.lineNumber,
		columns = g->pb.columnNumber;

	for (unsigned int i = 0; i < lines; i++) {
		for (unsigned int j = 0; j < columns; j++) {
			unsigned readableNum = i * lines + j;
			for (unsigned m = 0; m < g->pb.mineNumber; m++) {
				if (g->pb.mineLoc[m] == readableNum) {
					g->tab[i][j] = ELEMENTS::BOMB;
				}
			}
			if (g->tab[i][j] != ELEMENTS::BOMB) g->tab[i][j] = ELEMENTS::VOID;
			g->tab[i][j] = minesNearby(g, i, j);
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

	std::cout << std::endl;

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

	//std::cin >> nbrStroke;

	fillGrid(&gr);
	printGrid(&gr);

	//delete memory
	for (unsigned i = 0; i < line; i++) {
		delete[] gr.tab[i];
	}
	delete[] gr.tab;
}

int main() {

	srand((unsigned)time(NULL));

	int cmd;
	bool loop = true;

	while (loop) {
		std::cin >> cmd;
		switch (cmd) {
		case 1:
			createProblem();
			break;

		case 2:
			createGrille();
			break;

		case 3:
			break;

		case 4:
			break;

		case 5:
			break;

		case 6:
			loop = false;

		default:
			std::cin.ignore(17, '\n');
			std::cout << "Commande inconnue" << std::endl;

		}
	}
}