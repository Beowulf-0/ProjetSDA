#ifndef _FILE_
#define _FILE_

/**
 * @file File.h
 * Projet sem06-tp-Cpp2
 * @author l'équipe pédagogique
 * @version 2 - 13/01/10
 * @brief Composant de file d'items stockée dans une chaîne à simple chaînage
 * Structures de données et algorithmes - DUT1 Paris 5
 */

#include "Chaine.h"

 /**
  *  File utilisant une conteneur Chaine en mémoire dynamique
  */
struct File {
	mutable Chaine ch;	 // chaîne conteneur des éléments de file
};

/**
 * @brief initialiser une file vide
 * la file est allouée en mémoire dynamique
 * @see detruire, elle est à désallouer en fin d’utilisation
 * @param[out] f : la file à initialiser
 */
void initialiser(File& f);

/**
 * @brief Désallouer une file
 * @see initialiser, la file a déjà été allouée en mémoire dynamique
 * @param[out] f : la file
 */
void detruire(File& f);

/**
 * @brief Test de file vide
 * @param[in] f : la file testée
 * @return true si f est vide, false sinon
 */
bool estVide(const File& f);

/**
 * @brief Lire l'item en tête de file
 * @param[in] f : la file
 * @return la valeur de l'item en tête de file
 * @pre la file n’est pas vide
 */
Item tete(const File& f);

/**
 * @brief Entrer un item dans la file
 * @param[in,out] f : la file
 * @param[in] it : l'item à entrer
 * @pre f n’est pas pleine
 */
void entrer(File& f, const Item& it);

/**
 * @brief Sortir l’item tête de file
 * @param[in,out] f : la file
 * @pre f n’est pas vide
 */
void sortir(File& f);

#endif
