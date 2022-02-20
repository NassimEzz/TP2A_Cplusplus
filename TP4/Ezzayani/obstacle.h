#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <iostream>

class Obstacle {
	private :
		bool bound = false;
	public :
		virtual void recoitPalet(); // pour pouvoir override sur les fils
		bool get_ifLinked();
		void linked();
};

#endif