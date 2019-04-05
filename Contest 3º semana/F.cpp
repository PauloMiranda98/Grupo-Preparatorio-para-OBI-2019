#include <iostream>

using namespace std;

int tacos[1000010];
//Todos os valores de vetores globais em C++ são inicializados com 0.

int main() {
	int n, fabricados = 0;
	cin >> n;
	
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		
		if(tacos[x] == 0){
			fabricados += 2;
			tacos[x]++;
		}else{
			tacos[x]--;			
		}
	}
	
	cout << fabricados << "\n";
	
	return 0;
}
