#include <iostream>
#include <ostream>
#include <set>
#include <vector>
#include <stack>
#include <iterator>
#include <ctime>
using namespace std;

void remplir(vector<int> & vect)
{
	int value;
	int i=40;
	vector<int>::iterator ptr;

	while(i>0){
		value= rand() % 21;
		vect.push_back(value);
		i--;
	}

	cout << "Les elements du vecteur sont : ";
	for(ptr=vect.begin(); ptr<vect.end() ; ptr++){
		cout << *ptr << " ";
	}
	cout << " " << endl;
}

void remplirSet(set<int> & ensemble)
{
	int value;
	int i=1000;
	set<int>::iterator itr;

	while(i>0){
		value= rand() % 21;
		ensemble.insert(value);
		i--;
	}

	cout << "Les elements de l'ensemble sont : ";
	for(itr=ensemble.begin(); itr != ensemble.end() ; itr++){
		cout << *itr << " ";
	}
	cout << " " << endl;
}


// pour stack;
/*
template <typename T>
void remplir(stack<T> & stack)
{
	stack<T>::iterator stc;
	stack.begin();
}
*/
template <class iterator>
void affiche(iterator deb,iterator fin){
	cout << "Les elements sont : ";
	for(deb=deb; deb != fin ; deb++){
		cout << *deb << " ";
	}
	cout << " " << endl;
}


int main(int, char *[])
{
	srand(time(nullptr));
	vector<int> vecteur;
	set<int> ensemble;

	remplir(vecteur);
	remplirSet(ensemble);

	cout << " - Pour l'ensemble :" << endl;
	affiche(ensemble.begin(),ensemble.end());
	cout << " - Pour le vecteur :" << endl;
	affiche(vecteur.begin(),vecteur.end());
	
	return 0;
}
