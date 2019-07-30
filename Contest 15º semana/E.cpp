#include <bits/stdc++.h>

using namespace std;
const int MAXN = 10010;
typedef pair<int, int> pii;

vector<pii> adj[MAXN];
int dist[MAXN];

void dfs(int u, int p){
	for(pii to : adj[u]){
		if(to.first == p)
			continue;
		dist[to.first] = dist[u] + to.second;
		dfs(to.first, u);
	}
}
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int n, a, b;
	cin >> n >> a >> b;
	
	for(int i=1; i<n; i++){
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back(pii(y, w));
		adj[y].push_back(pii(x, w));
	}
	
	dist[a] = 0;
	dfs(a, -1);
	
	cout << dist[b] << endl;
	
	return 0;
}
