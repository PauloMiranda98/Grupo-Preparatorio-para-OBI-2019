#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

set<int> adj[MAXN];
int n, m;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	cin >> n >> m;
	
	for(int i=0; i<m; i++){
		int t, a, b;
		cin >> t >> a >> b;
		
		if(t == 0){
			if(adj[a].count(b))
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}else{
			adj[a].insert(b);
			adj[b].insert(a);
		}
	}

	return 0;
}
