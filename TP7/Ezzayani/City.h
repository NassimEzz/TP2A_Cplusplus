#include <iostream>
#include <ostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm> 
#include <functional>
#include <sstream>
#include <map>
using namespace std;

// QUESTION  A : 
struct City {
    string cityName;
    int postcode;
    

    int get_departement(){
        return postcode/1000;
    }
};

// QUESTION  C : 
using tabCity=vector<City>;

// QUESTION  E : 
using Predicat = function<bool(City&)>;

std::ostream &operator<<(std::ostream &out, const City &c);
tabCity lecture(string fileName);
tabCity select(tabCity & tab, Predicat & p);
tabCity select1(tabCity & tab, Predicat & p);
void departement(string filename);
Predicat city_and(Predicat p1, Predicat p2);
bool has_ville_suffix(City & cite);
bool is_in_calvados(City & cite);