#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
const int INF = 0x3f3f3f3f;

vector<int> chefe[510];
bool visitado[510];

//Idade das pessoas
int idade[510];

//Onde as pessoas estão
int id[510];

//Retorna a menor idade começando por u
int dfs(int u){
	int ans = INF;
	
	visitado[u] = true;
	
	for(int v: chefe[u]){
		if(!visitado[v]){
			ans = min(ans, dfs(v));
			ans = min(ans, idade[v]);
		}
	}
	return ans;
}

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	
	for(int i=1; i<=n; i++){
		cin >> idade[i];
		id[i] = i;
	}	

	for(int i=0; i<m; i++){
		int x, y;
		cin >> x >> y;
		
		//Guardamos o chefe de cada pessoa
		chefe[y].push_back(x);
	}	
	//Percebemos que o grafo não muda, o que muda é a localização das pessoas.

	//id[i] = Em qual nó está a pessoal i
	//idade[i] = Idade da pessoa no nó i do grafo

	for(int i=0; i<q; i++){
		char op;
		cin >> op;

		
		if(op == 'T'){
			int a, b;
			cin >> a >> b;			
			
			//Em qual nó está a pessoa A e B
			int noA = id[a];
			int noB = id[b];
			
			//Trocamos a idade de quem está nos Nós
			swap(idade[noA], idade[noB]);
			
			//Trocamos onde a pessoa A e B vão ficar
			swap(id[a], id[b]);
		}else{
			int e;
			cin >> e;
			
			//Onde a pessoa E está
			int noE = id[e];
			
			for(int i=1; i<=n; i++)
				visitado[i] = false;
			
			int ans = dfs(noE);
			
			if(ans == INF)
				cout << "*" << endl;
			else
				cout << ans << endl;
		}
	}
	
	
	return 0;
}
