#include <iostream>
using namespace std;

int mat[20][20];

int main() {
	int n;
	int soma = 0;
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> mat[i][j];
		}
	}
	
	for(int i=0; i<n; i++)
		soma += mat[0][i];

	//Verificar Linha
	for(int i=0; i<n; i++){
		int somaAtual = 0;
		for(int j=0; j<n; j++){
			somaAtual += mat[i][j];
		}
		if(somaAtual != soma){
			cout << "-1\n";
			return 0;
		}
	}
	
	//Verificar Coluna
	for(int j=0; j<n; j++){
		int somaAtual = 0;
		for(int i=0; i<n; i++){
			somaAtual += mat[i][j];
		}
		if(somaAtual != soma){
			cout << "-1\n";
			return 0;
		}
	}
	
	//Verificar a diagonal principal
	int somaAtual = 0;
	for(int d=0; d<n; d++){
		somaAtual += mat[d][d];
	}
	if(somaAtual != soma){
		cout << "-1\n";
		return 0;
	}
	somaAtual = 0;
	for(int i=0; i<n; i++){
		somaAtual += mat[i][n-1-i];
	}
	if(somaAtual != soma){
		cout << "-1\n";
		return 0;
	}
	
	cout << soma << "\n";
			
	return 0;
}
