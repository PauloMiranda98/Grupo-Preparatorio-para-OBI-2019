#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
#define MAXN 100010

struct Node{
	int max; //Maior valor do Nó
	int min; //Menor valor do Nó
	int ans; //Melhor resposta
	Node(){
		max = -INF;
		min = INF;
		ans = 0;
	}
	Node(int mx, int mn, int a){
		max = mx;
		min = mn;
		ans = a;
	}
};

struct SegTree{

	#define NSeg MAXN
	int n, *v;
	
	Node tree[4*NSeg];
	Node neutral;
	
	Node join(Node a, Node b){		
		//O maior valor da união de A e B é o máximo valor entre a A.max e B.max
		//O menor valor da união de A e B é o mínimo valor entre a A.min e B.min
		//A melhor resposta da união de A e B é a maior entre (A.max-B.min), (B.max-A.min), A.ans e B.ans 
		
		int ans_ab = max(a.max - b.min, b.max - a.min);
		
		return Node(max(a.max, b.max), min(a.min, b.min), max(ans_ab, max(a.ans, b.ans)));
	}

	void build(int node, int i, int j){
		if(i == j){
			//Quando tem apenas um balde a melhor resposta é zero
			tree[node] = Node(v[i], v[i], 0);
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
			v[index] = value;
			//Quando tem apenas um balde a melhor resposta é zero
			tree[node].max = max(tree[node].max, value);
			tree[node].min = min(tree[node].min, value);
			tree[node].ans = 0;
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
		Node node = query(1, 1, n, a, b);
		return node.ans;
	}
	
	void update(int i, int value){
		update(1, 1, n, i, value);
	}
};

SegTree st;
int n, m, v[MAXN];

int main() {	
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
		
	cin >> n >> m;

	for(int i=1; i<=n; i++){
		cin >> v[i];
	}
	
	st.build(v, n);
		
	for(int i=0; i<m; i++){
		int op;		
		cin >> op;
		if(op == 1){
			int index, value;
			cin >> value >> index;
			st.update(index, value);	
		}else{
			int a, b;
			cin >> a >> b;
			cout << st.query(a, b) << endl;
		}
	}
		
	return 0;
	
}
