all: robot

BrazoRobotico.o: BrazoRobotico.cpp BrazoRobotico.h

	g++ -c BrazoRobotico.cpp

main.o: main.cpp BrazoRobotico.h

	g++ -c main.cpp  

robot: main.o BrazoRobotico.o

	g++ -o robot main.o BrazoRobotico.o

clean: 
	
	rm -f *.o robot

test: all

	./robot

