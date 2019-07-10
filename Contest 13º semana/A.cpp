#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

const ll INFLL = 0x3f3f3f3f3f3f3f3fLL;
const int MAXN = 200010;

vector<pii> adj[MAXN];
int n, m;
ll dist[MAXN];
int pai[MAXN];

void Dijkstra(int s){	
	for(int i=0; i<=n; i++){
		dist[i] = INFLL;	
		pai[i] = -1;
	}	
	
	dist[s] = 0;
	priority_queue< pii, vector<pii>, greater<pii> > st;	
	st.push(pii(dist[s], s));
	
	while(!st.empty()){
		ll w = st.top().first;
		int u = st.top().second;
		st.pop();
		if(w > dist[u])
			continue;
		for(pii p: adj[u]){
			ll edge = p.first;  
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
	cin >> n;
	cin >> m;
	
	for(int i=0; i<m; i++){
		int a, b;
		ll w;
		cin >> a >> b >> w;
		
		adj[a].push_back(pii(w, b));
		adj[b].push_back(pii(w, a));
	}
	
	Dijkstra(1);
	
	cout << dist[n] << endl;
			
	return 0;
}
