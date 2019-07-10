#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int INFLL = 0x3f3f3f3f;
const int MAXN = 252;

vector<pii> adj[MAXN];
int mat[MAXN][MAXN];
int n, m, c, k;

int dist[MAXN];
int pai[MAXN];
int rota[MAXN];

void Dijkstra(int s){	
	for(int i=0; i<=n; i++){
		dist[i] = INFLL;	
		pai[i] = -1;
	}	
	
	dist[s] = 0;
	priority_queue< pii, vector<pii>, greater<pii> > st;	
	st.push(pii(dist[s], s));
	
	while(!st.empty()){
		int w = st.top().first;
		int u = st.top().second;
		st.pop();
		if(w > dist[u])
			continue;
		for(pii p: adj[u]){
			int edge = p.first;  
			int to = p.second;
			if(w+edge < dist[to]){
				dist[to] = w + edge;
				pai[to] = u;
				st.push(pii(dist[to], to));
			}
		}
	}
}


int main(){
	
	while(true){
		cin >> n >> m >> c >> k;
		
		if( !(n or m or c or k) )
			break;
			
		//Limpando a matriz de adjacência
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				mat[i][j] = -1;

		//Lendo a entrada
		for(int i=0; i<m; i++){
			int a, b, w;
			cin >> a >> b >> w;

			mat[a][b] = w;
			mat[b][a] = w;
		}
		
		//Calculando a distância para sair de i para c-1, dentro da rota
		rota[c-1] = 0;
		for(int i=c-2; i>=0; i--){
			rota[i] = rota[i+1] + mat[i][i+1];
		}
		
		//Limpando a lista de adjacência
		for(int i=0; i<n; i++)
			adj[i].clear();

		//Reconstruindo o grafo de tal forma que será necessário apenas chamar o Dijkstra
		for(int i=c; i<n; i++){
			//Caso exista uma ligação de i para um vertice j entre 0 e c-1, criamos uma aresta diretamente que liga i e c-1 com o somatório do peso da rota j..c-1
			for(int j=0; j<c; j++){
				if(mat[i][j] != -1){
					adj[i].push_back({mat[i][j] + rota[j], c-1});
					adj[c-1].push_back({mat[i][j] + rota[j], i});
				}
			}
			//Caso normal
			for(int j=c; j<i; j++){
				if(mat[i][j] != -1){
					adj[i].push_back({mat[i][j], j});
					adj[j].push_back({mat[i][j], i});
				}				
			}
		}
		
		Dijkstra(k);
		
		cout << dist[c-1] << endl;
	}
	
	return 0;
}
