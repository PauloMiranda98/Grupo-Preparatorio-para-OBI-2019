#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define F first
#define S second

#define MAXN 100010

struct Node{
	//pii (soma, tamanho)
	//soma do intervalo, melhor resposta, melhor prefixo e melhor sufixo
	pii total, res, pre, suf;
	
	Node(){
		total = res = pre = suf = pii(0, 0);  
	}
	
	Node(int x){
		total = res = pre = suf = pii(x, 1);  
	}
};

Node join(Node a, Node b){
	//Verificar se é o elemento Neutro
	if(a.total.S == 0)
		return b;
	if(b.total.S == 0)
		return a;
	
	Node c;
	//Soma total e tamanho da junção
	c.total = pii(a.total.F + b.total.F, a.total.S + b.total.S);
	
	//Melhor resposta e tamanho (Lembrando que no pair se o first empatar o desempate é feito pelo second)
	//Com isso, se o first for igual, ele pega o que tem o maior second
	pii resAB = pii(a.suf.F + b.pre.F, a.suf.S + b.pre.S);	
	c.res = max(resAB, max(a.res, b.res));
	
	//melhor prefixo
	c.pre = max(a.pre, pii(a.total.F + b.pre.F, a.total.S + b.pre.S));	

	//melhor prefixo
	c.suf = max(pii(a.suf.F + b.total.F, a.suf.S + b.total.S), b.suf);
	
	return c;
}


struct SegTree{
	 
	int n, *v;
	
	Node tree[4*MAXN];
	Node neutral;

	void build(int node, int i, int j){
		if(i == j){
			tree[node] = Node(v[i]);
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
	
	Node query(int a, int b){
		return query(1, 1, n, a, b);
	}	
};

SegTree st;
int n, v[MAXN];

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int t;
	cin >> t;
	
	while(t--){		
		cin >> n;

		for(int i=1; i<=n; i++){
			cin >> v[i];
		}
		
		st.build(v, n);
		
		int q;
		cin >> q;
		
		for(int i=0; i<q; i++){
			int a, b;
			cin >> a >> b;
			Node ans = st.query(a, b);
			cout << ans.res.F << " " << ans.res.S << '\n';
		}
		
	}
	return 0;
	
}
