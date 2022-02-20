#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

class Complex 
{
    private :
    
        double reel;
        double img;

    public :

        Complex();
        Complex(double r,double i);
        //Complex(double m,double a); Ne peut pas etre fait car surcharge
        Complex(const Complex & c);
        Complex & operator=(const Complex & c);
        Complex & operator+(const Complex & c);
        Complex & operator-(const Complex & c);
        Complex & operator*(const Complex & c);
        double getReal();
        double getImg();
        double getMod();
        double getArg();
        void affiche();
        void modifie();

};

Complex somme(Complex c1,Complex c2);
Complex produit(Complex c1,Complex c2);
Complex dif(Complex c1,Complex c2);
Complex normalized(Complex c);
void rotate(Complex & c,double o);
Complex& grand_module(Complex & c1,Complex & c2);
void racine_nieme(int n,Complex * tabcmp);
Complex foo( Complex a, Complex b);