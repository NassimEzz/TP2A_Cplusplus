#ifndef SET_H
#define SET_H

#include <iostream>
#include <ostream>
#include <iosfwd>
using namespace std;


template <typename T>
class Set
{
public:
	
	Set(){
		_list = nullptr;
	}
	
	Set(T x){
		_list = new Node(x);
	}
	
	~Set(){
		delete[] _list;
	}

	bool is_empty() const{
		if(_list==nullptr){
			return true;
		}
		return false;
	}

	bool contains(T x) const{
		if(is_empty()){
			return false;
		}

		Node *actuel;

		actuel=_list;
		
		while(actuel){
			if(actuel->getValue()==x){
				return true;
			}
			actuel=actuel->getNext();
		}
		return false;
		
	}

	void insert(T x){
		Node *last = _list;

		Node *nouv = new Node(x);

		if(is_empty()){
			_list=nouv;
		} else {
			while(last->getNext()!=nullptr){
				last=last->getNext();
			}
			last->setNext(nouv);
		}
	}

	void remove(T x){
		if(contains(x)){
			Node *parcours = _list;
			Node *trouve;

			if(parcours->getValue()==x){
				_list = parcours->getNext();
				delete parcours;
			} else {
				while(parcours->getNext()){
					trouve=parcours->getNext();
					if(trouve->getValue()==x){
						parcours->setNext(trouve->getNext());
						delete trouve;
						break;
					}
					parcours=trouve;
				}
			}
		}
	}

	void clear(){
		Node *actuel;
		Node *suivant;

		actuel=_list;

		while(actuel){
			suivant=actuel->getNext();
			delete actuel;
			actuel=suivant;
		}
		_list=nullptr;
	}

	void insertInto(Set<T> & sOther) const{
		Node *parcours;

		parcours=_list;

		while(parcours){
			sOther.insert(parcours->getValue());
			parcours=parcours->getNext();
		}
	}

	Set<T> & operator=(const Set<T> & sOther){
		if(this==&sOther){
			return *this;
		}
		clear();
		sOther.insertInto(*this);
		return *this;
	}

	bool isSubsetOf(const Set<T> & sOther) const{
		Node *parcours;

		while(parcours){
			if(!sOther.contains(parcours->getValue())){
				return false;
			}
			parcours=parcours->getNext();
		}
		return true;
	}

	void removeFrom(Set<T> & sOther) const{
		Node *parcours;

		parcours=_list;

		while(parcours){
			sOther.remove(parcours->getValue());
			parcours=parcours->getNext();
		}
	}

	Set(const Set<T> & sOther){
		_list=nullptr;
		*this=sOther;
	}

private:
	class Node {
	public:
    	Node(T value, Node * next = nullptr){
    		_value=value;
    		_next=next;
    	}
   	 	
   	 	T getValue() const{
   	 		return _value;
   	 	}
    	
    	Node * getNext() const{
    		return _next;
    	}
    	
    	void setNext(Node * next){
    		_next = next;
    	}

    private:
   		T _value;
    	Node * _next;
    };

    Node * _list;
	

    static Node * remove(Node * list, T x){
    	Node *parcours = list;
		Node *trouve;

		if(list->getValue()==x){
			list = parcours->getNext();
			delete parcours;
		}
		while(parcours->getNext()!=nullptr){
			trouve=parcours->getNext();
			if(trouve->getValue()==x){
				parcours->setNext(trouve->getNext());
				delete trouve;
				break;
			}
			parcours=trouve;
		}
	}
	
	friend std::ostream & operator<<(std::ostream & out, const Set<T> & s){
		out << "{";
		Node *parcours;
		parcours= s._list;
		while(parcours){
			if(parcours->getNext()){
				out<<parcours->getValue()<<",";
				parcours=parcours->getNext();
			} else {
				out<<parcours->getValue();
				parcours=parcours->getNext();
			}		
		}
		out<<"}"<<endl;
		return out;
	}

	friend Set<T> operator&(const Set<T>  & a, const Set<T>  & b){
    	if(a==b){
      	  return b;
  		}

    	Set<T> resultat;

    	Node * parcours = a._list;

		while(parcours)
		{ 
			if(b.contains(parcours->getValue())){
				resultat.insert(parcours->getValue());
			}
			parcours = parcours->getNext();
		}
    	return resultat;
	}

};


template<typename T>
Set<T> emptySet(){
    return Set<T>();
}

template<typename T>
Set<T> singleton(T x){
	return Set<T>(x);
}

template<typename T>
bool operator==(const Set<T> & a, const Set<T> & b){
	if(a.isSubsetOf(b) && b.isSubsetOf(a)){
		return true;
	}
	return false;
}

template<typename T>
Set<T> operator|(Set<T> & a, const Set<T> & b){
	Set<T> resultat;
    resultat=a;
    b.insertInto(resultat);
	return resultat;
}

/*
template<typename T>
Set<T> operator-(const Set<T> & a, const Set<T> & b){
    if(&a==&b){
        return emptySet<T>();
    }

    Set<T> resultat;

    resultat=a;

    b.removeFrom(a);

	return(resultat);
}
*/
template<typename T>
bool operator<(const Set<T> & a, const Set<T> & b){
    if(a==b){
        return true;
    }
    return a.isSubsetOf(b);
   
    return false;
}

template<typename T>
bool operator>(const Set<T> & a, const Set<T> & b){
    if(a==b){
        return true;
    }
    return b.isSubsetOf(a);
    return false;
}


#endif

