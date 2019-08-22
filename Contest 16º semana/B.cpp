#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAXN 100010

struct SegTree{
	typedef int Node;
	 
	int n, *v;
	
	Node tree[4*MAXN];
	Node neutral = 0;

	Node join(Node a, Node b){
		return max(a, b);
	}

	void build(int node, int i, int j){
		if(i == j){
			tree[node] = v[i];
			return;
		}
		int m = (i+j)/2;
		
		int l = (node<<1);
		int r = l + 1;
		
		build(l, i, m);
		build(r, m+1, j);
		
		tree[node] = join(tree[l], tree[r]);
	}

	Node query(int node, int i, int j, int a, int b){
		if( (i>b) or (j<a) )
			return neutral;
		if( (a<=i) and (j<=b) )
			return tree[node];
			
		int m = (i+j)/2;
		
		int l = (node<<1);
		int r = l + 1;
		
		return join( query(l, i, m, a, b), query(r, m+1, j, a, b) );
	}
	
	void build(int _v[], int _n){
		n = _n;
		v = _v;
		build(1, 1, n);
	}
	
	int query(int a, int b){
		return query(1, 1, n, a, b);
	}
	
};

SegTree st;
int n, v[MAXN];

int main() {		
	cin >> n;

	for(int i=1; i<=n; i++){
		cin >> v[i];
	}
	
	st.build(v, n);
	
	int ans = 0;
	
	for(int i=2; i<=(n-1); i++){
		//Verificar se existe alguém maior à esquerda e à direita
		if(st.query(1, i-1) > v[i] and st.query(i+1, n) > v[i])
			ans++;
	}	
	
	cout << ans << endl;
		
	return 0;
	
}
