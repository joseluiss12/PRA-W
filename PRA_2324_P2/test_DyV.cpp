#include <iostream>
#include <vector>
#include "DyV.h"


int main(){

	int i;
	std::vector<int> a{0,1,2,3,4,5,6,7,8,9};
	std::vector<char> b{'a','b','c','d','e','f','g','h','i','j'};
	std::vector<int> c{9,8,7,6,5,4,3,2,1,0};
	std::vector<char> d{'j','i','h','g','f','e','d','c','b','a'};
	std::vector<int> e{23,45,1,78,2,56,32,78,98,23};
	std::vector<char> f{'g','s','r','c','q','a','j','y','d','b'};
	std::cout << "Busqueda Binaria enteros: " << BusquedaBinaria(7,a,0,9) << std::endl;
	std::cout << "Busqueda Binaria caracteres: " << BusquedaBinaria('b',b,0,9) << std::endl;
	std::cout << "Busqueda Binaria enteros inversa: " << BusquedaBinaria_INV(7,c,0,9) << std::endl;
	std::cout << "Busqueda Binaria caracteres inversa: " << BusquedaBinaria_INV('b',d,0,9) << std::endl;
	std::cout << "Vector de enteros a oredenar: [ ";
	for(i = 0; i < 10; i++)

		std::cout << e[i] << " ";

	std::cout << "]" << std::endl;
	QuickSort(e,0,9);
	std::cout << "QuickSort: [ ";
	for(i = 0; i < 10; i++)

                std::cout << e[i] << " ";

        std::cout << "]" << std::endl;
	std::cout << "Vector de caracteres a ordenar: [ ";
	for(i = 0; i < 10; i++)

                std::cout << f[i] << " ";

        std::cout << "]" << std::endl;
	QuickSort(f,0,9);
	std::cout << "QuickSort: [ ";
	for(i = 0; i < 10; i++)

                std::cout << f[i] << " ";

        std::cout << "]" << std::endl;
	e = {23,45,1,78,2,56,32,78,98,23};
        f = {'g','s','r','c','q','a','j','y','d','b'};
	std::cout << "Vector de enteros a oredenar: [ ";
        for(i = 0; i < 10; i++)

                std::cout << e[i] << " ";

        std::cout << "]" << std::endl;
        QuickSort_INI(e,0,9);
        std::cout << "QuickSort_INI: [ ";
        for(i = 0; i < 10; i++)

                std::cout << e[i] << " ";

        std::cout << "]" << std::endl;
        std::cout << "Vector de caracteres a ordenar: [ ";
        for(i = 0; i < 10; i++)

                std::cout << f[i] << " ";

        std::cout << "]" << std::endl;
        QuickSort_INI(f,0,9);
        std::cout << "QuickSort_INI: [ ";
        for(i = 0; i < 10; i++)

                std::cout << f[i] << " ";

        std::cout << "]" << std::endl;
	e = {23,45,1,78,2,56,32,78,98,23};
        f = {'g','s','r','c','q','a','j','y','d','b'};
        std::cout << "Vector de enteros a oredenar: [ ";
        for(i = 0; i < 10; i++)

                std::cout << e[i] << " ";

        std::cout << "]" << std::endl;
        QuickSort_MID(e,0,9);
        std::cout << "QuickSort_MID: [ ";
        for(i = 0; i < 10; i++)
 
                std::cout << e[i] << " ";

        std::cout << "]" << std::endl;
        std::cout << "Vector de caracteres a ordenar: [ ";
        for(i = 0; i < 10; i++)

                std::cout << f[i] << " ";

        std::cout << "]" << std::endl;
        QuickSort_MID(f,0,9);
        std::cout << "QuickSort_MID: [ ";
        for(i = 0; i < 10; i++)

                std::cout << f[i] << " ";

        std::cout << "]" << std::endl;

	return 0;

}
