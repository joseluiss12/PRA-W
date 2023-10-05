#include <iostream>
#include "BrazoRobotico.h"


BrazoRobotico::BrazoRobotico(double x, double y, double z){

	coorX = x;
	coorY = y;
	coorZ = z;

}

bool BrazoRobotico::coger(){

	obj = true;
	std::cout << "El objeto ha sido cogido\n";
	return obj;

}

bool BrazoRobotico::soltar(){

	obj = false;
	std::cout << "El objeto ha sido soltado\n";
	return obj;

}

void BrazoRobotico::mover(double x, double y, double z){

	std::cout << "El robot ha movido sus posiciones:\nDe X = " << coorX << " a X = " << x << "\n";
        std::cout << "De Y = " << coorY << " a Y = " << y << "\n";
	std::cout << "De Z = " << coorZ << " a Z = " << z << "\n";
	coorX = x;
        coorY = y;
        coorZ = z;

}
