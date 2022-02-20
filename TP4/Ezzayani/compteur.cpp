#include <iostream>
#include "compteur.h"

Compteur::Compteur(Obstacle *dernierCompteur){
	nbPassage = 0;
	lastC = dernierCompteur;
}

int Compteur::get_nbrPassage(){
	return nbPassage;
}

void Compteur::aZero(){
	nbPassage=0;
}

void Compteur::recoitPalet(){
	nbPassage ++;
	
	if (lastC != NULL){
		lastC->recoitPalet();
	}
}

Compteur::~Compteur() {
   delete[] lastC;
}


