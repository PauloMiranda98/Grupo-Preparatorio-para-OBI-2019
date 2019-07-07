#include <iostream>

using namespace std;
const int INF = 0x3f3f3f3f;

int matriz[202][202];
bool acessado[202][202];
int n, m;

int dfs(int x, int y, int v){
	int cont = 1;

	if(acessado[x][y] or (x>n) or (y>m) or (x<1) or (y<1) or (matriz[x][y] != v) )
		return 0;
		
	acessado[x][y] = true;

	cont += dfs(x, y-1, v);			
	cont += dfs(x, y+1, v);
	cont += dfs(x-1, y, v);
	cont += dfs(x+1, y, v);	

	return cont;
}

int main(){	
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=1; i <=n; i++){
		for(int j=1; j <=m; j++){
			cin >> matriz[i][j];			
		}
	}	

	int menor = INF;
	
	for(int i=1; i <=n; i++){
		for(int j=1; j <=m; j++){		
			if(!acessado[i][j]){
				int valor = dfs(i, j, matriz[i][j]);
				
				if(valor < menor)
					menor = valor;
			}
		}		
	}
	
	cout << menor << endl;
														 			   				
	return 0;
	
}   
