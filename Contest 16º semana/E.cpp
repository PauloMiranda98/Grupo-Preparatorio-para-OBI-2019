#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAXN 100010

struct SegTree{
	typedef int Node;
	 
	int n, *v;
	
	Node tree[4*MAXN];
	Node neutral = 1;

	Node join(Node a, Node b){
		return (a * b);
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

	void update(int node, int i, int j, int index, int value){
		if(i == j){
			tree[node] = v[index] = value;
			return;
		}		
		int m = (i+j)/2;
		
		int l = (node<<1);
		int r = l + 1;
		
		if(index <= m)
			update(l, i, m, index, value);
		else
			update(r, m+1, j, index, value);		
		
		tree[node] = join(tree[l], tree[r]);
	}
	
	void build(int _v[], int _n){
		n = _n;
		v = _v;
		build(1, 1, n);
	}
	
	int query(int a, int b){
		return query(1, 1, n, a, b);
	}
	
	void update(int i, int value){
		update(1, 1, n, i, value);
	}
};

SegTree st;
int n, q, v[MAXN];

int sinal(int x){
	if(x > 0)
		return 1;
	if(x < 0)
		return -1;		

	return 0;
}

int main() {		
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	while(cin >> n >> q){
		for(int i=1; i<=n; i++){
			cin >> v[i];
			//Só é necessário saber o sinal
			v[i] = sinal(v[i]);
		}
		
		st.build(v, n);
		
		for(int i=0; i<q; i++){
			char op;
			
			cin >> op;
			if(op == 'P'){
				int a, b;
				cin >> a >> b;
				int s = st.query(a, b);
				if(s>0)
					cout << "+";
				else if(s<0)
					cout << "-";
				else
					cout << "0";
			}else{
				int index, value;
				cin >> index >> value;
				st.update(index, sinal(value));	
			}
		}
		cout << endl;
	}		
	return 0;
	
}
