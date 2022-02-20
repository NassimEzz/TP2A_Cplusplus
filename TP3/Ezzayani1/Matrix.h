#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

class Matrix 
{

  private :

    int nbLignes;
    int nbColonnes;
    int ** matrice;
    static int nbOfCalls;

  public :


  //constructors:
  
    Matrix();
    Matrix(int nbLignes, int nbColonnes);
    Matrix(const Matrix & m);
    Matrix(Matrix && m);
    ~Matrix();

  //Operators:
  
    Matrix & operator= (const Matrix & m);
    Matrix & operator= (Matrix && m);
    Matrix & operator+ (const Matrix & m);
    Matrix & operator- (const Matrix & m);
    Matrix operator- () const;
    friend ostream & operator<< (ostream &out, const Matrix &m);
    friend istream & operator>> (istream &in, Matrix &m);
    Matrix & operator*(const Matrix & m);
    int* & operator[](const int &nb);


    Matrix transposer();
    Matrix Mineur(int r, int c) const;
    int determinant();
    int getnbOfCalls();
    void initnbOfCalls();
    double cofacteur(int lig , int col);
  
};
