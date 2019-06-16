#include <iostream>

using namespace std;

int soma_linha[1010];
int soma_coluna[1010];
int matriz[1010][1010];

int main(){		
	
	int n, soma_max=0;
	cin >> n;
	
	for(int i=0;i<n; i++){
		for(int j=0; j<n; j++){
			cin >> matriz[i][j];
			
			soma_linha[i] += matriz[i][j];
			soma_coluna[j] += matriz[i][j];
		}
	}
	
	//o valor soma_linha[i] me informa qual a soma da linha i
	//o valor soma_coluna[j] me informa qual a soma da coluna j
	
	for(int i=0;i<n; i++){
		for(int j=0; j<n; j++){
			int aux =  soma_linha[i] + soma_coluna[j] - 2*matriz[i][j];

			soma_max = max(soma_max, aux);
			//A função max retorna o maior entre os dois valores.
		}
	}
	
	cout << soma_max << "\n";
	
	return 0;
}
