#ifndef CLOU_H
#define CLOU_H

#include "obstacle.h"
#include <iostream>

class Clou : public Obstacle {
	private :
		Obstacle *aDroite;
		Obstacle *aGauche;	
	public :
		Clou(Obstacle *deGauche, Obstacle *deDroite); // lie les clous 
		void  recoitPalet();
		~Clou();
};

#endif