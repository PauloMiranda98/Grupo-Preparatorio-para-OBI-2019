#include <iostream>

using namespace std;

int nE[70];
int nD[70];
//Todos os valores de vetores globais em C++ são inicializados com 0.
	
int main() {
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		int numero;
		char pe;
		cin >> numero >> pe;
		
		if(pe == 'E')
			nE[numero]++;
		else
			nD[numero]++;
	}
	
	int resultado = 0;
	for(int i=30; i<=60; i++){
		resultado += min(nE[i], nD[i]);
		//A função min retorna o minimo entre os dois valores.
	}
	
	cout << resultado << "\n";

	return 0;
}
