#include <bits/stdc++.h>

using namespace std;

int n, ans;
vector<int> adj[100010];

//Retorna a quatidade de nós da subarvore enraizado por u
int dfs(int u, int p){
	int qtd_no = 1;	
	
	//Para cada aresta que vejo analiso o resultado de cortar ela
	for(int to: adj[u]){
		if(to == p)
			continue;
			
		int x = dfs(to, u);
		int resto = n-x;
		ans = min(ans, abs(resto-x));

		qtd_no += x;
	}
	
	return qtd_no;
}

int main() {	
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
		
	cin >> n;

	for(int i=1; i<n; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	ans = 0x3f3f3f3f;
	dfs(1, -1);
	
	cout << ans << endl;
		
	return 0;
	
}
