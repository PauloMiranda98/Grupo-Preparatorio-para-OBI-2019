#include <bits/stdc++.h>

using namespace std;

int n;

char mat[1010][1010];

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> mat[i][j];
		}
	}
	//Ideia: Verificar se existe um '.' entre dois '*' da mesma linha ou da mesma coluna.
	//       caso exista, a resposta é 'N', caso contrário a resposta é 'S'.
	
	//Analisar linha
	for(int i=0; i<n; i++){
		int a=0; //Posição do primeiro '*' da linha i
		int b=n-1; //Posição do último '*' da linha i
		while(a<n and mat[i][a]!='*')
			a++;
		while(b>=0 and mat[i][b]!='*')
			b--;
		for(int j=a; j<=b; j++){
			if(mat[i][j]=='.'){ //Se encontrar um '.' entre dois '*' da mesma linha
				cout << 'N' << '\n';
				return 0;
			}
		}
	}

	//Analisar Coluna
	for(int j=0; j<n; j++){
		int a=0; //Posição do primeiro '*' da coluna j
		int b=n-1; //Posição do último '*' da coluna j
		while(a<n and mat[a][j]!='*')
			a++;
		while(b>=0 and mat[b][j]!='*')
			b--;
		for(int i=a; i<=b; i++){
			if(mat[i][j]=='.'){ //Se encontrar um '.' entre dois '*' da mesma coluna
				cout << 'N' << '\n';
				return 0;
			}
		}
	}

	cout << 'S' << '\n';

	return 0;
}
