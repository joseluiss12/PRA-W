#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

int cambio(std::vector<int>monedas, int N, int M, int matrix[4][9], int infinito){

	for(int i = 0; i <= M; i++)
		
		matrix[0][i] = infinito;


	for(int j = 0; j <= N; j++)

		matrix[j][0] = 0;	

	for(int w = 1; w <=M; w++){

		for(int q = 1; q <= N; q++){

			if(monedas[q-1] > w)
				
				matrix[q][w] = matrix[q-1][w];

			else

				matrix[q][w] = std::min(matrix[q-1][w], (matrix[q][w-monedas[q-1]])+1);

		}

	}

	/*int x = N;
	int z = M;
	while(z > 0){

		if(x > 1 && matrix[x][z] == matrix[x-1][z])
			
			i--;
		else

			z -= moneda[x-1];

	}*/

	return matrix[N][M];

}

int main(){

	int M = 8;
	int N = 3;
	int matrix[4][9];
	int infinito = std::numeric_limits<int>::max();
	std::vector<int> monedas = {1,4,6};
	int solucion = cambio(monedas,N,M,matrix,infinito);
	for(int d = 0; d <= N; d++){

		for(int g = 0; g <= M; g++){

			std::cout << matrix[d][g] << " ";

		}

		std::cout << std::endl;

	}	
	std::cout << solucion << std::endl;

	return 0;

}
