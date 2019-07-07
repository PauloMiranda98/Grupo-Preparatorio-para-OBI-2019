#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

int n;
vector<int> adj[MAXN];
bool mal;

int dfs(int u) {
    int qtd = 1;
    int qtd_filho = -1;
    
    for(int to : adj[u]) {
		int x = dfs(to);            
		qtd += x;
		
		
		if(qtd_filho == -1){//Primeiro filho
			qtd_filho = x;
		}else{
			if(x != qtd_filho)//Verificar se os filhos são iguais
				mal = true;
		}
	}
    
    return qtd;
}

int main(){	
	
	cin >> n;

	for(int i=0; i<n; i++){
		int a, b;
		cin >> a >> b;
		
		adj[b].push_back(a);
	}
	
	dfs(0);
	if(mal){
		cout << "mal" << endl;
	}else{
		cout << "bem" << endl;		
	}
	
	return 0;	
}
