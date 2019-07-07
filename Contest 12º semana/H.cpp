#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

int n, m;
vector<int> adj[MAXN];
bool used[MAXN] ;

void dfs(int u) {
    used[u] = true ;
    for(int to : adj[u]) {
        if (!used[to])
            dfs(to);
    }
}

int find_comps() {
	int cont = 0;
    for(int i = 1; i <= n ; ++i)
        used [i] = false;
    for(int i = 1; i <= n ; ++i){
        if (!used[i]) {
            dfs(i);
            cont++;
        }
	}
	
	return cont;
}


int main(){	
	
	cin >> n >> m;

	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	cout << find_comps() << endl;
	
	return 0;	
}
