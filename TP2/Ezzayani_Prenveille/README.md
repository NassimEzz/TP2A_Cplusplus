### TP2 C++
### Ezzayani Nassim
### Prenveille Arno


## 1.2

Un message d'erreur est émis car l'accès aux membres privés d'une classe est interdit. Pour que cela soit possible, il faut passer par un getter.

## 1.4

Cela est impossible car pour créer un tel constructeur, il faudrait utiliser un prototype qui fait passer deux double en argument, et ce prototype est déjà utilisé par un constructeur de Complexe. Il est tout de même possible de rajouter un argument supplémentaire inutilisé pour différencier les deux constructeurs, même si ce n'est pas une solution réellement envisageable. L'utilisation d'un namespace aurait pu être envisageable, mais cela génère un erreur à la compilation.

## 1.5

Il faut créer des surchages d'opérateur de la forme suivante :

```C++
Complex & Complex::operator#(const double & d);
```

Dans lesquels on créé un complexe à partir du double et on utilise la surcharge créé précedemment dans le tp.

## 2 

Il suffit dans cette question de rajouter des " cout << << endl" pour afficher les messages et rajoutant en plus des "this" pour avoir les adresses rendant ainsi la sortie plus lisible.

## 3.1

Pour cette question il suffit de divisier la partie reel et imaginaire par le module en utilisant le constructeur.

## 3.2

Pour cette question on va utilise "la reference" etant le choix qui va nous permettre d'avoir le resultat attendu , la rotation dans le plan complexe etant une multiplication il nous suffit de creer un complexe rotation.

## 3.4

les 3 premieres lignes :
"0x7ffd96340b90:+++Complex(0,0)
0x7ffd96340ba0:+++Complex(1,1)
0x7ffd96340bb0:+++Complex(2,2)"

->Correspondent aux trois variables complexes z1, z2 et z3 suite à l'utilisation du constructeur qui signale la creation.

ensuite :
"Calling foo()"

->Correspond au cout qu'on a utilisé.

suivi de :
"0x7ffd96340bd0:rrrComplex(1+ i.1)
0x7ffd96340bc0:rrrComplex(0+ i.0)"

->C'est la création des variables des arguments de la fct foo grâce au constructeur par recopie.

ensuite on a les 3 lignes de la foction foo qui s'execute :

"0x7ffd96340be0:+++Complex(10,10)"

-> Etant la creation du complexe z(10,10)

"0x7ffd96340be0:op=Complexe(0+ i.0)
0x7ffd96340be0:op=Complexe(1+ i.1)
0x7ffd96340bb0:op=Complexe(1+ i.1)"

-> qui correspond a l'utilisation de l'operateur surchage "=" pour ecraser la variable "z" deux foix puis la retourne.

enfin on a :

"End of main()"

-> qui est le cout final du main.