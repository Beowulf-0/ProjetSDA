/**
 * @file File.cpp
 * Projet sem06-tp-Cpp2
 * @author l'équipe pédagogique
 * @version 2 - 13/01/10
 * @brief Composant de file d'items stockée dans une chaîne à simple chaînage
 * Structures de données et algorithmes - DUT1 Paris 5
 */

#include <cassert>
#include "File.h"

 /**
  * @brief initialiser une file vide
  * la file est allouée en mémoire dynamique
  * @see detruire, elle est à désallouer en fin d’utilisation
  * @param[out] f : la file à initialiser
  */
void initialiser(File& f) {
	// Codez la fonction ......................................................
	initialiser(f.ch);
}

/**
 * @brief Désallouer une file
 * @see initialiser, la file a déjà été allouée en mémoire dynamique
 * @param[out] f : la file
 */
void detruire(File& f) {
	detruire(f.ch);
}

/**
 * @brief Test de file vide
 * @param[in] f : la file testée
 * @return true si f est vide, false sinon
 */
bool estVide(const File& f) {
	// Codez la fonction ......................................................
	if (estVide(f.ch)) {
		return true;
	}
	return false;
}

/**
 * @brief Lire l'item en tête de file
 * @param[in] f : la file
 * @return la valeur de l'item en tête de file
 * @pre la file n’est pas vide
 */
Item tete(const File& f) {
	Maillon* m = f.ch.tete;
	return m->elem;
}

/**
 * @brief Entrer un item dans la file
 * @param[in,out] f : la file
 * @param[in] it : l'item à entrer
 */
void entrer(File& f, Item& it) { //note : toujours cibler la file à la fin.
	fin(f.ch);
	inserer(f.ch, it);
}

/**
 * @brief Sortir l’item tête de file
 * @param[in,out] f : la file
 * @pre f n’est pas vide
 */
Case sortir(File& f) { //note : toujours cibler la file au début.
	assert(!estVide(f));
	Case c;
	debut(f.ch);
	c = tete(f);
	supprimer(f.ch);
	return c;
}


