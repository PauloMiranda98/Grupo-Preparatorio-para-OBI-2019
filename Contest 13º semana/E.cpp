#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1010;

vector<pii> adj[MAXN];
int n, m;
int dist[MAXN];

void Dijkstra(int s){	
	for(int i=0; i<=n+1; i++){
		dist[i] = INF;	
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
				st.push(pii(dist[to], to));
			}
		}
	}
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
	
	Dijkstra(0);
	
	cout << dist[n+1] << endl;
			
	return 0;
}
	
