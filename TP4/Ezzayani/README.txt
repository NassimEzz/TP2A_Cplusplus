Ezzayani Nassim

Report TP4 C++ :

1.

###Creation des 5 classes : 

--> POUR LA PLANCHE : les variables ont deja été données.

---> POUR OBSTACLE : 
	- Je me crée une variable de type bool pour savoir si l'obstacle est lié ou non dans le sens est ce qu'il est dans une relation père-fils ou non cela est utile pour la desallocation après.

	- 2 methodes pour gerer cette variable : une pour la recuperer et l'autre pour la changer dans le cas d'une liaison.

	- une methode virtuel (recoitPalet) pour la redefinir dans l'heritage (Clou et Compteur).

---> POUR CLOU : 
	- 2 variable qui ne sont autres que les succeseurs droit et gauche de ce clou donc soit des clous soit des compteurs , la desallocation se fait encore suivant le bool d'obstacle.

	- 1 constructeur surchargé par les voisins suivant histoire de lié l'obstacle à sa création aux autres obstacles.

	-REDEF de la methode herite recoitPalet() pour qu'elle fait passer le Palet à l'obstacle suivant avec une probabilite de recuperation de 1/2 pour l'obstacle de droite et de gauche.

	- 1 destructeur.

---> POUR COMPTEUR :

	- 1 variable pour compter le nombre de passage.
	- 1 pour lie la ligne des compteurs au dernier compteur (d'ou le nom choisi).

	- 1 constructeur qui lie en meme temps les compteurs au compteur final et dans le cas du compteur final donnera a la variable un NULL.

	-REDEF de la methode herite recoitPalet() pour qu'elle incremente le compteur de 1 et dans le cas d'une presence d'un compteur final lui fait passer le Palet.

	- une methode pour recuperer le nombre de passage et une autre pour remettre le compteur a Zero.

	- 1 destructeur.

---> POUR LANCEUR :
	
	- 1 varible qui n'est d'autre que la racine ie le premier element qui va recevoir le Palet.

	- 1 constructeur pour initialiser cette racine.

	- 1 methode qui lance le jeu en lancant le Palet sur la racine.


### Pour les methodes :

---> planche.cpp :

	- Distingue le cas où le parametre N (nombre de compteur du dernier rang) est egale à 0 ou à 1 et dans ces 2 cas il n'y a que le dernier compteur et pas de Clou.

	- Pour la simulation : 
		-on recupere au debut le resultat du compteur.
		-on lance les NbPalet Palet sur la racine.
		-on recupere les resultats dans un tableau et on affiche le round.

/!\/!\/!\/!\ 
		- TP en monome..