#include "City.h"

int main(int, char *[]){
    City city1{"Paris",14200};
    City city2{"Tokyo",1147};
    City city3{"London",14300};
    tabCity france;

    cout << "La surcharge de l'operateur << donne : " << endl;
    cout << city1 << endl;
    cout << city2 << endl;
    cout << city3 << endl;
    cout << " " << endl;

    cout << "Test de la fonction de lecture en affichant le 1er et 46eme element du vecteur : " << endl;
    france = lecture("metropole.csv");  
    cout << france[0] << endl;
    cout << france[45] << endl;
    cout << " " << endl;
    
    cout << "Test de la fonction select avec un predicat qui chercher le cityname Paris 15: " << endl;
    tabCity res2;
    Predicat pr1=[](City & cite){   return cite.cityName == "PARIS 15";};
    res2=select1(france,pr1);
    cout << res2[0] << endl;
    cout << " " << endl;


    cout << "Test de la fonction select2 pour les departements : " << endl;
    departement("metropole.csv");
    cout << " " << endl;

    cout << "Test de la fonction de merge de 2 predicat : " << endl;
    Predicat reu;
    Predicat pr2=[] (City & cite){ return cite.postcode == 75015;};
    reu=city_and(pr1,pr2);
    res2=select1(france,reu);
    cout << res2[0] << endl;
    cout << " " << endl;

    cout << "Le nombre de villes du calvados avec 'VILLE' dans leur nom est : " << count_if(france.begin(), france.end(), city_and(has_ville_suffix,is_in_calvados)) << endl;
    cout << " " << endl;


    // QUESTION l:
    map<int,int> franceDepart;
    int i=1;

    //On cree un tableau associatif avec pour chaque numero du departement le nombre de ville avec 'ville'
    while(i<100){
        franceDepart[i]= count_if(france.begin(), france.end(),city_and([i](City & cite){ return cite.get_departement()==i;},has_ville_suffix));
        i++;
    }

    map<int,int>::iterator mapitr;

    int k=0;
    int dep;
    for(mapitr=franceDepart.begin();mapitr!=franceDepart.end();mapitr++){
        if(k<mapitr->second){
            k=mapitr->second;
            dep=mapitr->first;
        }
    }

    cout << "Le numero du departement avec le plus de villes en 'VILLE' est le : " << dep << "eme"<< endl;    
    return 0;
}