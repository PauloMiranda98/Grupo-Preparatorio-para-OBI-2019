#include <iostream>

using namespace std;

int v[1010];
int main() {
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	int picos = 0;
	
	//O i inicia de 1 e vai até n-1 para evitar o acesso de posições inválidas.
	for(int i=1; i<(n-1); i++){
		if( (v[i-1] < v[i]) and (v[i+1] < v[i]) )
			picos++;
	}
	
	if(picos > 1)
		cout << "S" << "\n";
	else
		cout << "N" << "\n";

	return 0;
}

