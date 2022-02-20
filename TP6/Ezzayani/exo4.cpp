#include <iostream>
#include <ostream>
#include <vector>
#include <map>
#include <iterator>
#include <ctime>
using namespace std;

template <typename T,typename U,typename V,typename W>
bool paires(T x,U y,V x1,W y1){
    pair <T,U> pair1;
    pair <V,W> pair2;

    pair1=make_pair(x,y);
    pair2=make_pair(x1,y1);

    return pair1<pair2;

}

int main(int, char *[])
{
    map<string,int> age;
    map<string,int>::iterator mery;

    age["mira"]=21;
    age["nas"]=22;
    age["sirine"]=17;
    age["saf"]=20;
    age["yous"]=19;
    age["sky"]=32;
    age["leo"]=28;
    age["riad"]=15;


    for(mery=age.begin(); mery != age.end() ; mery++){
		cout << " Pour la clé : '" << mery->first << "' , on a la valeur : '" << mery->second <<"'." << endl;
	}    

    cout << " " << endl;
    cout << " Pour les pairs" << endl;

    cout << " - pour (1,10) < (2,3) : "<< paires(1,10,2,3) << endl;
    cout << " - pour (1,10) < (1,20) : "<< paires(1,10,1,20) << endl;
    cout << " - pour (1,10) < (1,5) : "<< paires(1,10,1,5) << endl;
    //cout << " (1,10) < (0,8.5) : "<< paires(1,10,0,8.5) << endl;
    cout << " - pour (1,10) < (0,8.5) : message d'erreur probleme avec comparaison entre int et double"<<endl;
    cout << " - pour (0,5) < (0,5) : "<< paires(0,5,0,5) << endl;
    cout << " - pour (\"pomme\",10) < (\"tomate\",3) : "<< paires("pomme",10,"tomate",3) << endl;
    pair<int,int> int1;
    pair<int,int> int2;
    int1= make_pair(0,0);
    int2=make_pair(0,8);
    bool res= int1!=int2;
    cout << " - pour (0,0)!=(0,8) : " << res << endl;

    return 0;
}