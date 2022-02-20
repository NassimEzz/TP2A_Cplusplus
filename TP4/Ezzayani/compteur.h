#ifndef COMPTEUR_H
#define COMPTEUR_H

#include "obstacle.h"
#include <iostream>

class Compteur : public Obstacle {
	private :
		int nbPassage;
		Obstacle *lastC;

	public :
		Compteur(Obstacle *dernierCompteur); // pour le dernier compteur
		void recoitPalet();
		int get_nbrPassage();
		void aZero();
		~Compteur();
};

#endif