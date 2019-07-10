#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10010;

int n;
vector<int> adj[MAXN];
int dist[MAXN];
int a, b;

void dfs(int u, int p) {    
    for(int to : adj[u]) {
		if(to != p){
			dist[to] = dist[u] + 1;
			dfs(to, u);            
		}
	}
}

int main(){	
	
	cin >> n >> a >> b;

	for(int i=1; i<n; i++){
		int x, y;
		cin >> x >> y;
		
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	dist[a] = 0;
	dfs(a, -1);
	
	cout << dist[b] << endl;
	
	return 0;	
}
