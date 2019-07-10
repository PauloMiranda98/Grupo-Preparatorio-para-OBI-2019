#include <bits/stdc++.h>
//#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<pii> adj[100010];
int peso[100010];
int pai[100010];
bool vis[100010];
int n, m;

ll prim(int s){
	memset(peso, 0x3f, sizeof(peso));
	memset(vis, 0, sizeof(vis));
	peso[s] = 0;
	
	priority_queue<pii, vector<pii>, greater<pii> > st;
	st.push(pii(peso[s], s));
	
	while(!st.empty()){
		int u = st.top().second;
		st.pop();
		if(vis[u])
			continue;
		vis[u] = true;
		
		for(pii p: adj[u]){
			int edge = p.first;
			int to = p.second;
			
			if(!vis[to] and (edge < peso[to]) ){
				peso[to] = edge;				
				pai[to] = u;
				st.push(pii(peso[to], to));
			}
		}
	}
	
	ll ans = 0;
	for(int i=2; i<=n; i++){
		ans += peso[i];
	}
	return ans;
}

int main(){
	cin >> n;
	cin >> m;
	
	for(int i=0; i<m; i++){
		int a, b, w;
		cin >> a >> b >> w;
		
		adj[a].push_back(pii(w, b));
		adj[b].push_back(pii(w, a));
	}
	
	cout << prim(1) << endl;
	
	return 0;
}
