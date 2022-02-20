#include <iostream>
#include "planche.h"
using namespace std ;

int main(){
	Planche p(2); //test de la creation
	cout << "je lance 4 PALET" << endl;
	p.simulation(4);	
	return 0;
}