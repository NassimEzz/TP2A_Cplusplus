#include <iostream>
#include <ostream>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <iterator>
#include <ctime>
using namespace std;

template <typename T>
vector<T> trier(vector<T> & vect){
    priority_queue<T> file;

    T value;
	int i=40;
	typename vector<T>::iterator ptr;

	while(i>0){
		value= rand() % 30;
		vect.push_back(value);
		i--;
	}

    for(ptr=vect.begin();ptr<vect.end();ptr++){
        file.push(*ptr);
    }

    vector<T> res(file.size());

    for(i=file.size();i>0;i--){
        res[i]=file.top();
        file.pop();
    }

    return res;

}

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
    vector<int> nontrie;
    vector<int> trie;
    trie=trier(nontrie);


    cout << "Avant de trier on a : " << endl;
    affiche(nontrie.begin(),nontrie.end());
    cout << "Apres avoir trier on a : " << endl;
    affiche(trie.begin(),trie.end());
    
    return 0;
}