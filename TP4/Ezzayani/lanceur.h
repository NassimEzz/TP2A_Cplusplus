#ifndef LANCEUR_H
#define LANCEUR_H

#include "obstacle.h"
#include <iostream>

class Lanceur {
	private :
		Obstacle *racine; // recuperer le premier clou à la creation du lanceur

	public :
		Lanceur(Obstacle *premClou); 
		void lancer();//lancer sur le premier clou

};

#endif	