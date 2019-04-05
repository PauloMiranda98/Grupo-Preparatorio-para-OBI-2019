#include <iostream>
#include <vector>

using namespace std;

int cor[110];
vector<int> adj[110];
int n, q;

//DFS(no atual, no anterior, no destino, cor para pintar)
//Retorna se o no U foi pintado ou não
bool dfs(int u, int p, int d, int c){	
	if(u == d){
		cor[u] = c;
		return true;
	}
	
	bool faz_parte = false;
	
	for(int v : adj[u]){
		
		//Para evitar que eu volte para quem me chamou
		if(v != p){
			bool v_pintado = dfs(v, u, d, c);

			if(v_pintado == true)
				faz_parte = true;			
		}
	}
	
	if(faz_parte == true){
		cor[u] = c;
	}
	
	return faz_parte;
}

int main() {
	
	cin >> n >> q;
	
	for(int i=1; i<n; i++){
		int a, b;
		cin >> a >> b;
		
		//Montando a lista de adjacência
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int i=0; i<q; i++){
		int a, b, c;
		cin >> a >> b >> c;
		
		//Pintando o caminho
		dfs(a, 0, b, c);
	}
	
	for(int i=1; i<=n; i++)
		cout << cor[i] << " ";

	cout << "\n";

	return 0;
}
