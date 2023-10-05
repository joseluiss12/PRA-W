#include <iostream>
#include "BrazoRobotico.h"

int main(){

	BrazoRobotico R1(10.3,5.2,27.6);
	R1.coger();
	R1.mover(30.2,7,12.9);
	R1.soltar();

	return 0;

}
