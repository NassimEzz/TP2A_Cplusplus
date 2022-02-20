#include <iostream>
#include <ostream>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <iterator>
#include <ctime>
using namespace std;
// QST 5.a :

template <class iterator>
void inclusion(iterator deb,iterator fin,iterator deb1,iterator fin1){
	int k=0;
    int j=0;
    if(deb==fin){
        cout << "La premiere sequence est bien incluse dans la deuxieme " << endl;
        return;
    }
    for(deb=deb; deb != fin ; deb++){
		j++;
        for(deb1=deb1 ; deb1!=fin1 ; deb1++){
            if(*deb==*deb1){
                k++;
                break;
            }
        }
        if(k!=j){
            cout << "La premiere sequence n'est pas incluse dans la deuxieme " << endl;
            return;
        }
	}
	cout << "La premiere sequence est bien incluse dans la deuxieme " << endl;
}

// ## QST 5.b

template <class iterator>
void affiche(iterator deb,iterator fin){
	cout << "Les elements sont : ";
	for(deb=deb; deb != fin ; deb++){
		cout << *deb << " ";
	}
	cout << " " << endl;
}

template <class iterator>
vector<typename iterator_traits<iterator>::value_type> trier(iterator deb,iterator fin){
    priority_queue<typename iterator_traits<iterator>::value_type> file;

    for(deb=deb;deb!=fin;deb++){
        file.push(*deb);
    }

    vector<typename iterator_traits<iterator>::value_type> res(file.size());

    for(int i=file.size();i>0;i--){
        res[i]=file.top();
        file.pop();
    }

    return res;
}

// QST 5.c

template <class iterator>
void echange(iterator ptr1,iterator ptr2){
    typename iterator_traits<iterator>::value_type tmp = *ptr1;
    tmp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=tmp;
}

int main(int, char *[])
{
    vector<int> vecteur1;
    vector<int> vecteur2;

    for(int i=5;i<10;i++){
        vecteur1.push_back(i);
    }

    for(int k=0;k<10;k++){
        vecteur2.push_back(k);
    }

    cout << " ## QUESTION 5.a : " << endl;
    cout << "-Pour {5,6,7,8,9} C {0,1,2,3,4,5,6,7,8,9} : " << endl;
    inclusion(vecteur1.begin(),vecteur1.end(),vecteur2.begin(),vecteur2.end());

    vector<int> vecteur3;
    vector<int> vecteur4;

    for(int k=0;k<10;k++){
        vecteur3.push_back(k);
    }

    for(int k=0;k<5;k++){
        vecteur4.push_back(k);
    }
    
    cout << "-Pour {0,1,2,3,4,5,6,7,8,9} C {5,6,7,8,9}  : " << endl;
    inclusion(vecteur3.begin(),vecteur3.end(),vecteur4.begin(),vecteur4.end());

    cout << " " << endl;
    cout << " ## QUESTION 5.b : " << endl;

    vector<int> vect={ 5,43,22,66,52,12,99,2,7,18,26,32,37};
    vector<int> resultat;
    
    cout << "--> Avant de trier on a : " << endl;
    affiche(vect.begin(),vect.end());
    cout << "--> Apres avoir trier on a : " << endl;
    resultat=trier(vect.begin(),vect.end());
    affiche(resultat.begin(),resultat.end());

    cout << " " << endl;
    cout << " ## QUESTION 5.c : " << endl;
    echange(resultat.begin()+3,resultat.begin()+8);
    cout << "--> Apres avoir echange les positions : " << endl;
    affiche(resultat.begin(),resultat.end());

   return 0;
}