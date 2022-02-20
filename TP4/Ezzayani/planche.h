#ifndef PLANCHE_H
#define PLANCHE_H

#include "obstacle.h"
#include "compteur.h"
#include "clou.h"
#include "lanceur.h"
#include <iostream>

class Planche {
	private :
		Lanceur* lanceur;
		int nbCounter;
		Compteur** counters;
		Compteur* lastCounter;

	public :
		Planche(int nbLastRankCntr);
		void simulation(int nbPalet);

};

#endif