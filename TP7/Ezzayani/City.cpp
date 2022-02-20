#include "City.h"

// QUESTION  B : 
std::ostream &operator<<(std::ostream &out, const City &c) {
    out << c.cityName <<"("<<c.postcode<<")"<<endl;
    return out;
}

// QUESTION  D : 
tabCity lecture(string fileName){
    tabCity resultat;
    ifstream csv(fileName);

    if(csv){
        int i=0;
        string line;
        string postal;
        int code;
        string name;
        City cite;

        while(getline(csv,line)){
            std::size_t pos = line.find(";");  
            postal = line.substr(0,pos);
            code=stoi(postal);
            name = line.substr(pos+1);
            cite.cityName=name;
            cite.postcode=code;
            resultat.push_back(cite);    
            i++;
        }
    } else {
        cout << " Error : can't open file" << endl;
    }

    csv.close();

    return resultat;
}

// QUESTION  F : 
tabCity select(tabCity & tab, Predicat & p){
    tabCity result;
    tabCity::iterator itr;

    for(itr=tab.begin() ; itr<tab.end() ; itr++){
        if(p(*itr)){
            result.push_back(*itr);
        }
    }

    return result;
}


// QUESTION  G : 

tabCity select1(tabCity & tab, Predicat & p){
    tabCity result;

    back_insert_iterator<tabCity> res (result);
    copy_if(tab.begin(),tab.end(),res,p);

    return result;
}

// QUESTION  H : 

void departement(string filename){
    tabCity aEtudier = lecture(filename);
    if(all_of(aEtudier.begin(),aEtudier.end(),[](City &cite) {return cite.get_departement()<100;})){
        cout << "Tous les departemens de ' " << filename << " ' sont compris entre 0 et 100." << endl;
    }
}

// QUESTION I :

Predicat city_and(Predicat p1, Predicat p2){
    return [p1,p2](City cite) { return (p1(cite) && p2(cite));};
}

// QUESTION J :

bool has_ville_suffix(City & cite){
    if(cite.cityName.find("VILLE")!=std::string::npos){
        return true;
    }
    return false;
}

bool is_in_calvados(City & cite){
    if(cite.get_departement()==14){
        return true;
    }
    return false;
}
