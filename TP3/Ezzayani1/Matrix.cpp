#include "Matrix.h"
#include <stdexcept>
#include <cmath>
using namespace std;
# define POWER(n) ((1)-(2)*(n%2))

int Matrix::nbOfCalls= 0;

/* 1 */

Matrix::Matrix() {
  int i;
  matrice = new int*[1];
  for(i=0; i < 1; i++) {
    matrice[i] = new int[1];
  }
  matrice[0][0]=0;
  nbLignes=1;
  nbColonnes=1;
}

Matrix::Matrix(int nbLigness, int nbColonness) {
  int k;
  matrice = new int*[nbLigness];
  for(k=0; k < nbLigness; k++) {
    matrice[k] = new int[nbColonness];
  }
  int i;
  int j;
  for (i=0; i < nbLigness; i++) {
    for (j=0; j < nbColonness; j++) {
      matrice[i][j] = 0;
    }
  }
  nbLignes=nbLigness;
  nbColonnes=nbColonness;
}

Matrix::Matrix(const Matrix & m) {
  int k;
  matrice = new int*[m.nbLignes];
  for(k=0; k < m.nbLignes; k++) {
    matrice[k] = new int[m.nbColonnes];
  }
  int i;
  int j;
  for(i=0; i < nbLignes; i++) {
    for(j=0; j < nbColonnes; j++) {
      matrice[i][j] = m.matrice[i][j];
    }
  }
    
}

Matrix::Matrix(Matrix && m) {
  cout << " execution du constructeur par deplacement sur Matrix(" << m.nbLignes << "," << m.nbColonnes << ")" << endl;
  this->nbLignes = m.nbLignes;
  this->nbColonnes = m.nbColonnes;
  memcpy(m.matrice, this->matrice, sizeof(int) * m.nbLignes * m.nbColonnes);
  this->matrice = nullptr;
  m.nbLignes = 0;
  m.nbColonnes = 0;
}

  Matrix & Matrix::operator= (const Matrix & m) {
    if (this == &m) {
      return *this;
    }
    nbLignes = m.nbLignes;
    nbColonnes = m.nbColonnes;
    matrice = m.matrice;
    return *this;
  }

  Matrix & Matrix::operator= (Matrix && m) {
    cout << " execution de l'operateur d'affectation par déplacement sur Matrix(" << m.nbLignes << "," << m.nbColonnes << ")" << endl;
    delete [] this->matrice;
    this->nbLignes = m.nbLignes;
    this->nbColonnes = m.nbColonnes;
    this->matrice = m.matrice;
    m.matrice = nullptr;
    m.nbLignes = 0;
    m.nbColonnes = 0;
    return *this;
  }

  ostream & operator<< (ostream &out, const Matrix &m) {
    int i;
    int j;
    for (i = 0 ; i<m.nbLignes ; i++) {
      for (j = 0 ; j<m.nbColonnes ; j++) {
        out << m.matrice[i][j];
      }
      out << endl;
    }
    return out;
  }
  istream & operator>> (istream &in, Matrix &m) {
    int i;
    int j;
    int nbLignes = 0;
    int nbColonnes = 0;
    cout << "Entrez le nombre de lignes :";
    in >> nbLignes;
    cout << "Entrez le nombre de colonnes :";
    in >> nbColonnes;
    m = Matrix(nbLignes, nbColonnes);
    cout << "Entrez les valeurs de la matrice (tapez entrée entre chaque valeur)";
    for (i = 0 ; i<m.nbLignes ; i++) {
      for (j = 0 ; j<m.nbColonnes ; j++) {
        in >> m.matrice[i][j];
      }
    }
    return in;
  }

  Matrix::~Matrix() {
    delete [] this->matrice;
  }

Matrix & Matrix::operator+(const Matrix & m)
{
  if( nbLignes != m.nbLignes || nbColonnes != m.nbColonnes) {
    cout << "not the same dimensions"<< endl;
  }
  int i;
  int j;
  for(i=0 ; i < nbLignes ; i++) {
    for(j=0; j < nbColonnes ; j++) {
      matrice[i][j] += m.matrice[i][j];
    }
  }
    return *this;
}

Matrix & Matrix::operator-(const Matrix & m)
{
  if( nbLignes != m.nbLignes || nbColonnes != m.nbColonnes) {
    cout << "not the same dimensions"<< endl;
  }
  int i;
  int j;
  for(i = 0; i < nbLignes ; i++) {
    for (j = 0; j < nbColonnes ; j++) {
      matrice[i][j] -= m.matrice[i][j];
    }
  }

  return *this;
}

Matrix & Matrix::operator*(const Matrix & m)
{
  if( nbColonnes != m.nbLignes) {
    cout << "not the right dimensions"<< endl;
  }
  Matrix tmp(nbLignes,m.nbColonnes);
  int i;
  int j;  
  for (i=0; i< nbLignes; i++) {
    for (j=0; j < nbColonnes; j++) {
      for (int k = 0; k < nbColonnes; k++) {
        tmp.matrice[i][j] = tmp.matrice[i][j] + ((matrice[i][k])*(m.matrice[k][j]));
      }
    }
  }
  
  return tmp;
}

int* & Matrix::operator[](const int &nb)
{
  return  matrice[nb];
}

Matrix Matrix::transposer()
{
  Matrix tmp(nbColonnes,nbLignes);
  int i;
  int j;
    for (i=0; i < nbLignes; i++) {
      for (j=0; j < nbColonnes; j++) {
        tmp.matrice[j][i] = matrice[i][j];
      }
    }
  
  return tmp;
}

/* ----------------------------------------------------- */
/* 3 */

Matrix Matrix::Mineur(int r, int c) const 
{
  Matrix matriceMin(nbLignes - 1, nbColonnes - 1);
  int ligner=0;
  int colc=0;
  
  for(int i=0; i<nbLignes;i++){
    if(i!=r){ 
      for(int j=0;j<nbColonnes;j++){
        if(j!=c) {
        matriceMin.matrice[i-ligner][j-colc]=matrice[i][j];
      } else {
        colc++;
      }
      }
    } else {
      ligner++;
    }
  }

  return matriceMin;
}

int Matrix::determinant() {
  
    if (nbLignes!=nbColonnes) {
        throw "The matrix should be square";
    }
    nbOfCalls++;

    if (nbColonnes == 1) {
        return matrice[0][0];
    }

    if (!nbColonnes){
      return 0;
    }
  
    int deter = 0;
  Matrix Z(nbLignes-1,nbColonnes-1);
  for (int j=0 ; j < nbColonnes ; j++) {
  //  Z.matrice  = (*this).Mineur(0,j);  ???
    deter += POWER(j)*matrice[0][j]*(Z.determinant());
  }
    return deter;
}


int Matrix::getnbOfCalls()  {
    return nbOfCalls;
}

void Matrix::initnbOfCalls() {
    nbOfCalls = 0;
}

/*  PROBLEME AVEC L'OPERATEUR *

double Matrix::cofacteur(int lig , int col) {
    return pow(-1, lig + col)*Mineur(lig, col);
}

*/