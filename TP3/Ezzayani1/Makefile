CC = g++
CFLAGS = -W -Wall

main : main.o Matrix.o
	$(CC) $^ -o $@ $(CFLAGS)

main.o : main.cpp Matrix.h
	$(CC) $^ -c $(CFLAGS)

Matrix.o : Matrix.cpp Matrix.h
	$(CC) $^ -c $(CFLAGS)

clean :
	rm *.o
	rm main
