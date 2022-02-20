TP 6

EZZAYANI NASSIM TP MONOME 

- REPORT OF TP6 C++ :


>> Question 1:
	
	- Pour l'ensemble on remarque qu'il n'affiche qu'au plus 20 element , ceci revient au propriete 
 	  du 'SET' qui enleve les doublons.
	
>> Question 2:
	- Cela revient au fait que les multi(set) et (multi)map sont associatifs pour les set et map 
	on n'a pas de doublons , mais pour les multi on en a.
	
### d- POUR STACK:
		
		exo1.cpp:53:9: error: expected primary-expression before ‘>’ token
   		53 |  stack<T>::iterator stc;
     		   |         ^
		exo1.cpp:53:21: error: missing template arguments before ‘stc’
   		53 |  stack<T>::iterator stc;
       	   |                     ^~~
		exo1.cpp:53:20: error: expected ‘;’ before ‘stc’
  	        53 |  stack<T>::iterator stc;
   
   AUSSI : 
   
  	 	exo1.cpp:53:8: error: ‘class std::stack<int>’ has no member named ‘begin’
   		53 |  stack.begin();
      	 	   |      


-----------> IL ne reconnait pas du tout la presence d'iterateur et donc ne dispose pas de begin().


>> Question 3:
	-le vecteur a une allocation dynamique et il n'augmente pas sa capacite que de ce dont 
	il a besoin mais bien en doublant sa capacite precedente à chaque fois ou cette derniere 
	est depasse.
	 
>> Question 4:
	- On remarque que l'ordre de remplissage du tableau n'est pas le meme que pour l'affichage , 
	c'est le role du 'less<string>' qui ordonne la MAP suivant les keys en comparants les strings : 
	premiere lettre , puis deuxieme si les premieres sont similaires ... et ainsi on obtient une MAP 
	ordonnée par key croissante.

>> Question 5:
	- l'utilite de ce modele est qu'il nous permet de creer des pairs avec les types des pairs qu'on 
	veut tout en ayant acces aux operateur de comparaison des memes types.

>> Question 6:
	- à l'instruction 'if' dés que le programme arrive au tab[0] vu qu'elle n'existe pas il la cree,
	et vu qu'il n'est pas deja presete dans la map (premiere occurence) il lui donne la valeur 0 
	et puis il passe au test qui donne un "TRUE" alors .

### EXO 5 :

	->> petit c : en C++11 on peut utiliser le "deltype" pour avoir le type.

