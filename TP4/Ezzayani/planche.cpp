#include <iostream>
#include <math.h>
#include "planche.h"
using namespace std;

Planche::Planche(int nbLastRankCntr) {
	int i;

	// variable nbCounter
	if(nbLastRankCntr == 1 || nbLastRankCntr == 0 ) {
		nbCounter = 1;
	} else {
		nbCounter = nbLastRankCntr + 1 ;
	}

	cout<<"nbCounter CREATED"<<endl;

	// le dernier compteur
	Compteur lastCounter(NULL);

	// la ligne des compteurs
	if(nbLastRankCntr!=1 && nbLastRankCntr!=0) {

		counters = (Compteur **)malloc((nbLastRankCntr)*sizeof(Compteur*));	

		for (i=0; i < nbLastRankCntr; i++){

			counters[i]= new Compteur(lastCounter);
		}
	} else {
		counters = NULL;
		cout << "il y'aura un seul compteur" << endl;
	}

	cout<<"COUNTERS CREATED"<<endl;

	// CREATION DES CLOUS
	if(nbLastRankCntr!=1 && nbLastRankCntr!=0) {
		Clou *** allStuds = (Clou ***)malloc((nbLastRankCntr-1)*sizeof(Clou**));
		Clou ** lastLine = (Clou**)malloc((nbLastRankCntr-1)*sizeof(Clou*));
		int j;

		//ligne juste avant les compteurs (LA DERNIERE)
		for ( j=0 ; j<nbLastRankCntr-1; j++){
			lastLine[j] = new Clou(counters[j],counters[j+1]);
		}
		allStuds[0] = (Clou**)malloc((nbLastRankCntr-1)*sizeof(Clou*));
		allStuds[0]=lastLine;	

		//le reste des CLOUS et le lanceur
		for ( j=nbLastRankCntr-2 ; j>0 ; j--) {
			Clou ** lastLine = (Clou**)malloc((j)*sizeof(Clou*));

			for(i=0; i<j ; i++) {
				lastLine[i]= new Clou(allStuds[nbLastRankCntr-j-2][i],allStuds[nbLastRankCntr-j-2][i+1]);
			}

			allStuds[nbLastRankCntr-j-1]=(Clou**)malloc((j)*sizeof(Clou*));
			allStuds[nbLastRankCntr-j-1]=lastLine;
		}

		lanceur = new Lanceur(*allStuds[nbLastRankCntr-2]);
		
	} else {
		cout << "il n'y pas de clou" << endl;
		lanceur = new Lanceur(&lastCounter);
	}

	cout<<"CLOUS CREATED"<<endl;
	
	cout<<"LANCEUR CREATED"<<endl;

	cout<<"PLANCHE FINIE"<<endl;

}

void Planche::simulation(int nbPalet){ 
	int k;
	int debut = lastCounter->get_nbrPassage();
	
	for(k=0 ; k<nbPalet ; k++){
		lanceur->lancer();
	}

	int compter[nbCounter-1];

	for(int i=0;i<nbCounter-1;i++){
		compter[i]=counters[i]->get_nbrPassage();
		cout << compter[i] << endl;
	}
}