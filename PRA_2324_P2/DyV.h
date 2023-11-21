#include <iostream>
#include <vector>


template<typename T>

int BusquedaBinaria(T x, std::vector<T>& v, int ini, int fin){

	if (ini > fin){

		std::cout << "No se encuentra en el array" << std::endl;
		return -1;

	}

	int medio = (ini + fin) / 2;
	if (v[medio] == x)

		return medio;

	else if (v[medio] > x)

		return BusquedaBinaria(x,v,ini,medio-1);

	else 

		return BusquedaBinaria(x,v,medio+1,fin);

}	


template<typename T>

int BusquedaBinaria_INV(T x, std::vector<T>& v, int ini, int fin){

	if (ini > fin){

		std::cout << "No se encuentra en el array" << std::endl;
		return -1;

	}

	int medio = (ini + fin) / 2;
	if (v[medio] == x)

		return medio;

	else if (v[medio] > x)

		return BusquedaBinaria_INV(x,v,medio+1,fin);

	else 

		return BusquedaBinaria_INV(x,v,ini,medio-1);

}


template<typename T>

void  Swap(T &a, T &b){

	T aux = a;
	a = b;
	b = aux;

}


template<typename T>

int Partition(std::vector<T>& v, int ini, int fin){

	T x = v[fin];
	int i = ini;
	for (int j = ini; j < fin; j++){

		if (v[j] <= x){

			Swap(v[i], v[j]);
			i++;

		}

	}

	Swap(v[i], v[fin]);
	
	return i;

}


template<typename T>

void QuickSort(std::vector<T>& v, int ini, int fin){

	if (ini < fin){

		int pivot = Partition(v,ini,fin);
		QuickSort(v,ini,pivot-1);
		QuickSort(v,pivot+1,fin);

	}

}


template<typename T>

int Partition_INI(std::vector<T>& v, int ini, int fin){

	T x = v[ini];
	int i = ini;
	for (int j = ini; j < fin; j++){

		if (v[j] <= x){

			Swap(v[i], v[j]);
			i++;

		}

	}

	Swap(v[i], v[ini]);

	return i;

}


template<typename T>

void QuickSort_INI(std::vector<T>& v, int ini, int fin){

	if (ini < fin){

		int pivot = Partition_INI(v,ini,fin);
		QuickSort_INI(v,ini,pivot-1);
		QuickSort_INI(v,pivot+1,fin);

	}

}


template<typename T>

int Partition_MID(std::vector<T>& v, int ini, int fin){

	int mid = (ini + fin) / 2;
        T x = v[mid];
        int i = ini;
        for (int j = ini; j < fin; j++){

                if (v[j] <= x){

                        Swap(v[i], v[j]);
                        i++;

                }

        }

        Swap(v[i], v[mid]);

        return i;

}


template<typename T>

void QuickSort_MID(std::vector<T>& v, int ini, int fin){

        if (ini < fin){

                int pivot = Partition_MID(v,ini,fin);
                QuickSort_MID(v,ini,pivot-1);
                QuickSort_MID(v,pivot+1,fin);

        }

}



