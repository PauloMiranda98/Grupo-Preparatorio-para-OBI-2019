#include <iostream>

using namespace std;

//Vector global sempre é inicializado com zero ou falso
bool figurinha[110];

int main(){		
	int n, c, m;
	cin >> n >> c >> m;
	
	for(int i=0; i<c; i++){
		int x;		
		cin >> x;
		figurinha[x] = true; 
	}

	for(int i=0; i<m; i++){
		int x;		
		cin >> x;
		figurinha[x] = false; 
	}
	
	int cont = 0;
	for(int i=1; i<=n; i++){
		if(figurinha[i])
			cont++;
	}
	
	cout << cont << endl;
	
	return 0;
}
