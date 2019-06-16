#include <iostream>
#include <algorithm>

using namespace std;

struct Carro{
	int pontuacao;
	int id;	
};

bool comparar(Carro a, Carro b){
	
	if(a.pontuacao == b.pontuacao){
		return (a.id < b.id);
	}else{
		return (a.pontuacao > b.pontuacao);
	}
	
}

Carro pilotos[102];
int valor[102];
int posicao[102][102];

int main(){

	int n, m, k, x, aux;	
	cin >> n >> m;
	
	while(n || m){

		for(int i=1; i<=n; i++){		
			for(int j=1; j<=m; j++){
				cin >> aux;			
				posicao[i][aux] = j; 
			}	
		}
			
		cin >> x;
		
		for(int i=1; i<=x; i++){		
			cin >> k;
			
			for(int a=1; a<=m; a++){		
				pilotos[a].id = a;
				pilotos[a].pontuacao = 0;	
			}
		
			for(int j=1; j<=k; j++){
				cin >> valor[j];
			}			
			
			for(int a=1; a<=n; a++){		
				for(int j=1; j<=k; j++){
					pilotos[posicao[a][j]].pontuacao += valor[j];
				}
			}
			
			sort(pilotos+1, pilotos+m+1, comparar);
			
			int maior = pilotos[1].pontuacao;
			
			for(int a=1; (a<=m) && (pilotos[a].pontuacao == maior); a++){
				if(a > 1)
					cout << " ";
				cout << pilotos[a].id;
			}
			
			cout << "\n";
					
		}
		
		cin >> n >> m;		
	}	
	
	return 0;
}
