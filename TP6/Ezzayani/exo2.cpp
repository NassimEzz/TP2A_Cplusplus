#include <iostream>
#include <ostream>
#include <vector>
#include <iterator>
#include <ctime>
using namespace std;

template <typename T>
void test(vector<T> & vect){
    T value;
    int i=5000;

    while (i>0)
    {
        value= rand() % 21;
		vect.push_back(value);
        i--;
        cout << "La taille/nmbr d'element du vecteur est : ";
        cout << vect.size() << endl;
        cout << "La capacite du vecteur est : ";
        cout << vect.capacity() << endl; 
    }
}

int main(int, char *[])
{
    srand(time(nullptr));
	vector<double> vecteur;
    test(vecteur);
    return 0;
}