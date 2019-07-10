#include <bits/stdc++.h>
using namespace std;

#define MAXN 210
#define MAXM 20010

struct UnionFind{	
	int n, anc[MAXN], w[MAXN], sz[MAXN];

	UnionFind(){
		for(int i=1; i<MAXN; i++){
			anc[i] = i;
			w[i] = 1;
			sz[i] = 1;
		}		
	}

	//find: O(1)
	int find(int x){    
		if(anc[x] == x)
			return x;		
		return anc[x] = find(anc[x]);
	}

	//isSame: O(1) 
	bool isSame(int x, int y){
		return find(x) == find(y);
	}

	//join: O(1) 
	void join(int x, int y){    
		x = find(x);
		y = find(y);
		
		if(x == y)
			return;
		
		if(w[x] < w[y]){
			anc[x] = y;
			sz[y] += sz[x];
		}else if(w[x] > w[y]){
			anc[y] = x;
			sz[x] += sz[y];
		}else{        
			anc[x] = y;
			sz[y] += sz[x];
			
			w[y]++;
		}
	}
	
	int size(int x){
		return sz[find(x)];
	}
};

int n, f, r, m;

typedef long long ll;
typedef tuple<ll, int, int> tp;

tp edgeList[MAXM];

ll kruskal() {
	ll cost = 0;
	UnionFind uf;
	
	for(int i = 0; i < m; i++) {
		int u, v; ll c;
		tie(c, u, v) = edgeList[i];
		
		if(!uf.isSame(u, v ) ) { 
			cost += c;
			uf.join(u, v);
		}
	}
	
	return cost;
}

//Para resolver essa questão, estude Union Find e Kruskal

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> f >> r;
	m = f+r;
	
	for(int i=0; i<f; i++){
		int u, v; ll w;
		cin >> u >> v >> w;
		edgeList[i] = tp(w, u, v);
	}
	sort(edgeList, edgeList+f);

	for(int i=f; i<f+r; i++){
		int u, v; ll w;
		cin >> u >> v >> w;
		edgeList[i] = tp(w, u, v);
	}	
	sort(edgeList+f, edgeList+f+r);
	//Fazendo essa ordenação damos prioridade para as ferrovias
		
	cout << kruskal() << endl;
	
	return 0;
}
