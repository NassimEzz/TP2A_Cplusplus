#include "complex.h"

// 1.1

Complex::Complex(){
    reel=0;
    img=0;
    cout << this << ":" << "+++Complex()" << endl;
}

Complex::Complex(double r,double i){
    reel=r;
    img=i;
    cout << this << ":" << "+++Complex("<< r << "," << i << ")" << endl;
}
    
Complex::Complex(const Complex & c){
    reel=c.reel;
    img=c.img;
    cout << this << ":" << "rrrComplex(" << c.reel << "+ i." << c.img << ")" << endl;

}


/*
Complex::Complex(double m,double a){
    reel = m*cos(a);
    img = m*sin(a);
}
*/

Complex & Complex::operator=(const Complex & c)
{
    reel = c.reel;
    img = c.img;
    cout << this << ":" << "op=Complexe(" << c.reel << "+ i." << c.img << ")" << endl;
    return *this;
}

double Complex::getReal(){
    return this->reel;
} 

double Complex::getImg(){
    return this->img;
}

double Complex::getMod(){
    return sqrt(pow(this->reel,2)+pow(this->img,2));
}

double Complex::getArg(){
    return atan(this->img/this->reel);
}

void Complex::affiche(){
    cout << this->reel << "+" << this->img <<"i"<< endl;
}

void Complex::modifie(){
    double k;
    k=this->img;
    this->img=this->reel;
    this->reel=k;
}


Complex somme(Complex c1,Complex c2){
    return Complex(c1.getReal()+c2.getReal(),c1.getImg()+c2.getImg());
}

Complex produit(Complex c1,Complex c2){
    return Complex(c1.getReal()*c2.getReal()-c1.getImg()*c2.getImg(),c1.getReal()*c2.getImg()+c2.getReal()*c1.getImg());
}

Complex dif(Complex c1,Complex c2){
    return Complex(c1.getReal()-c2.getReal(),c1.getImg()-c2.getImg());
}

// 1.3 surcharge

Complex & Complex::operator*(const Complex & c)
{
    double tmp = reel*c.reel - img*c.img;
    img = reel*c.img + img*c.reel;
    reel = tmp;
    return *this;
}

Complex & Complex::operator-(const Complex & c)
{
    reel = reel - c.reel;
    img = img - c.img;
    return *this;
}

Complex & Complex::operator+(const Complex & c)
{
    reel = reel + c.reel;
    img = img + c.img;
    return *this;
}

// Nouvelle version des fonctions pour les operations sur les complexes

Complex somme1(Complex c1,Complex c2){
    return c1+c2;
}

Complex produit1(Complex c1,Complex c2){
    return c1*c2;
}

Complex dif1(Complex c1,Complex c2){
    return c1-c2;
}

// 3.1

Complex normalized(Complex c){
    Complex c1(c.getReal()/c.getMod(),c.getImg()/c.getMod());
    return c1;
}

// 3.2

void rotate(Complex & c,double o){
    Complex c1(cos(o),sin(o));
    c=c*c1;
}

// 3.3

Complex& plus_grand_module(Complex & c1,Complex & c2){
    if((c1.getMod())>(c2.getMod())){
        return c1;
    } else {
          return c2;
    }
}

/*

// 3.4

void racine_nieme(int n,Complex * tabcmp){
    for(int i=0;i<n;i++){
        tabcmp[i]->reel=
        tabcmp[i]->reel=

    }
}
*/

// Test 

int main(){
    Complex c1(10,7);
    Complex c2(35,13);
    c1.affiche();
    c1.modifie();
    c1.affiche();
    c1.modifie();
    cout << "le module est : " << c1.getMod() << endl;
    cout << c1.getArg() << endl;
    somme1(c1,c2).affiche();
    produit1(c1,c2).affiche();
    dif1(c1,c2).affiche();
    Complex(12.2066,0.610726).affiche();
    Complex c3(25,30);
    rotate(c3,50);
    c3.affiche();
    c1=plus_grand_module(c2,c2*c2);


    return 0;
}




