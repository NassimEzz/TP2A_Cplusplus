#include <iostream>
#include <time.h>
#include "clou.h"


Clou::Clou(Obstacle *deGauche, Obstacle *deDroite){
	aGauche = deGauche;
	aDroite  = deDroite;

	// regarder si lié ou pas
	if (!deDroite->get_ifLinked()){	
		deDroite->linked();
	}
	
	if (!deGauche->get_ifLinked()){
		deGauche->linked();
	}

}

void Clou::recoitPalet(){
	srand(time(NULL));
	int i ;
	i = rand()%3+1; // valeur 1 ou 2
	if (i==1){
		aGauche->recoitPalet();
	} else {
		aDroite->recoitPalet();
	}
}

Clou::~Clou(){
	delete[] aGauche;
	delete[] aDroite;
}