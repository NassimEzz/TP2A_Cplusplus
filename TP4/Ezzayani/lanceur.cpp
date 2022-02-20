#include <iostream>
#include "lanceur.h"

Lanceur::Lanceur(Obstacle *premClou){
	racine = premClou;
}

void Lanceur::lancer(){
	racine->recoitPalet();
}