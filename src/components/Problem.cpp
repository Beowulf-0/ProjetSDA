#include "../headers/Problem.h"
#include <random>
#include <iostream>

void defineProblem(Problem &pb, unsigned lines, unsigned column, unsigned mines) {
    pb.lineNumber = lines;
    pb.columnNumber = column;
    pb.mineNumber = mines;
    pb.mineLoc = new Mine[pb.mineNumber];
}

void shuffleArray(Problem &p, unsigned int *tab) {
    unsigned int maxValue = p.lineNumber * p.columnNumber;
    unsigned int ech;
    for (unsigned int i = 0; i < p.mineNumber; i++) {
        unsigned j = std::rand() % maxValue;
        ech = tab[j];
        tab[j] = tab[i];
        tab[i] = ech;
    }
}

void generateMine(Problem pb, Mine *mineList) {
    //TODO: Security about Problem
    unsigned int maxValue = pb.columnNumber * pb.lineNumber;
    unsigned *tab;
    tab = new unsigned int[maxValue];
    for (unsigned i = 0; i < maxValue; i++) {
        tab[i] = i;
    }

    shuffleArray(pb, tab);

    for (unsigned m = 0; m < pb.mineNumber; m++) {
        mineList[m] = tab[m];
    }
    delete[] tab;
}

void showProblem(Problem &pb) {
    std::cout << pb.lineNumber << " " << pb.columnNumber
              << " " << pb.mineNumber << " ";
    for (unsigned i = 0; i < pb.mineNumber; i++) {
        std::cout << pb.mineLoc[i] << " ";
    }

    std::cout << "\n";
}

void deleteProblem(Problem &pb) {
    delete[] pb.mineLoc;
}

void createProblem() {
    unsigned line, column, mines;
    Problem problem{};

    std::cin >> line >> column >> mines;

    //Generate mines
    defineProblem(problem, line, column, mines);
    generateMine(problem, problem.mineLoc);

    showProblem(problem);

    //delete memory
    deleteProblem(problem);
}
