#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

int mochila(std::vector<int>& peso, std::vector<int>& precio, int N, int M, int matrix[5][6]){

	for(int i = 0; i < M; i++)
		
		matrix[0][i] = 0;


	for(int j = 0; j < N; j++)

		matrix[j][0] = 0;	

	for(int w = 1; w < N; w++){

		for(int q = 1; q < M; q++){

			if(q - peso[w-1] < 0)
				
				matrix[w][q] = matrix[w-1][q];

			else

				matrix[w][q] = std::max(matrix[w-1][q], (matrix[w-1][q-peso[w-1]]+ precio[w-1]));

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

	return matrix[N-1][M-1];

}

int main(){

	int M = 6;
	int N = 5;
	int matrix[5][6];
	std::vector<int> peso = {1,3,2,4};
	std::vector<int> precio = {10,20,15,20};
	for(int i = 0; i < M; i++){
    		for(int j = 0; j < N; j++){
            		matrix[i][j] = -1;
    		}
  	}
	int solucion = mochila(peso,precio,N,M,matrix);
	for(int d = 0; d < N; d++){

		for(int g = 0; g < M; g++){

			std::cout << matrix[d][g] << " ";

		}

		std::cout << std::endl;

	}	
	std::cout << solucion << std::endl;

	return 0;

}
