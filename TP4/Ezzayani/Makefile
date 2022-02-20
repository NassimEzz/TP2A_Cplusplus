CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11
LINK.o = $(LINK.cc)

.PHONY: all clean

all: main

main: lanceur.o obstacle.o compteur.o clou.o planche.o main.o

main.o: main.cpp lanceur.cpp compteur.cpp obstacle.cpp clou.cpp planche.cpp lanceur.h compteur.h obstacle.h clou.h planche.h 
	$(CXX) $(CXXFLAGS) -c $< -o $@

lanceur.o: lanceur.cpp lanceur.h obstacle.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

compteur.o: compteur.cpp compteur.h obstacle.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

obstacle.o: obstacle.cpp obstacle.h
	$(CXX) $(CXXFLAGS) -c $< -o $@		

clou.o: clou.cpp clou.h obstacle.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

planche.o: planche.cpp planche.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f main *.o