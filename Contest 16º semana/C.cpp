#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
const int NBIT = 1200010;

struct BIT{			
	int tree[NBIT];//2*6*10^5
	
	BIT(){
		memset(tree, 0, sizeof(tree));
	}
	
	int queryPos(int x){
		int sum = 0;
		int pos = 0;
		
		for(int i=21; i>=0; i--){
			if( (pos + (1 << i) < NBIT) and (sum + tree[pos + (1 << i)] <= x) ){
				sum += tree[pos + (1 << i)];
				pos += (1 << i);
			}
		}

		return pos;
	}
	
	int querySum(int i){	
		int s = 0;
		for( ; i > 0; i -= (i & -i))
			s += tree[i];		
		return s;
	}

	void update(int i, int value){				
		for( ; i < NBIT; i += (i & -i))
			tree[i] += value;
	}
	void clear(){
		memset(tree, 0, sizeof(tree));		
	}
	
};

int v[NBIT];

struct SegTree{	
	int tree[4*NBIT];
	int neutral = 0;
	SegTree(){
		v[0] = -INF;
	}

	int query(int node, int i, int j, int a, int b, int value){
		if( (i>b) or (j<a) )
			return neutral;
			
		if(i == j){
			if(v[tree[node]] > value)
				return tree[node];
			else
				return neutral;				 
		}
		
		if(v[tree[node]] <= value)
			return neutral;

		int m = (i+j)/2;
		
		int l = (node<<1);
		int r = l + 1;
		
		if( (a<=i) and (j<=b) ){
			int posL = tree[l];
			int posR = tree[r];
			
			if(v[posR] > value)
				return query(r, m+1, j, a, b, value);
			if(v[posL] > value)
				return query(l, i, m, a, b, value);
			return neutral;
		}else{
			int posR = query(r, m+1, j, a, b, value);

			if(v[posR] > value)
				return posR;

			int posL = query(l, i, m, a, b, value);
			if(v[posL] > value)
				return posL;

			return neutral;
		}
	}
	
	void update(int node, int i, int j, int index, int value){
		if(i == j){
			v[i] = value;
			tree[node] = i;
			return;
		}		
		int m = (i+j)/2;
		
		int l = (node<<1);
		int r = l + 1;
		
		if(index <= m)
			update(l, i, m, index, value);
		else
			update(r, m+1, j, index, value);	
				
		//retorna a posição que tem o maior valor
		if(v[tree[r]] >= v[tree[l]])
			tree[node] = tree[r];
		else
			tree[node] = tree[l];			
	}

	int query(int a, int b, int value){
		return query(1, 1, NBIT-10, a, b, value);
	}
	
	void update(int i, int value){
		update(1, 1, NBIT-10, i, value);
	}
};

struct Q{
	int t, i, x;
};

Q queries[1200010];
BIT posicao;
SegTree segtree;

int n, q;

int main() {
	
	scanf("%d", &n);
	
	//Salvando os valores iniciais
	//Vamos considerar o valores iniciais como inserção
	for(int i=0; i<n; i++){
		queries[i].t = 0;
		queries[i].i = i;		
		scanf("%d", &queries[i].x);	
 	} 	

	//Salvando as queries
 	scanf("%d", &q);
	for(int i=n; i<(n+q); i++){
		scanf("%d %d %d", &queries[i].t, &queries[i].i, &queries[i].x);
	}
	
	//Inicializar a BIT
	for(int i=1; i<=(n+q); i++){
		posicao.update(i, 1);	
	}	
		
	//Atualizando suas posições offlines
	for(int i=n+q-1; i>=0; i--){
		if(queries[i].t == 0){//inserir
			queries[i].i = posicao.queryPos(queries[i].i) + 1;
			posicao.update(queries[i].i, -1);		
		}else{
			queries[i].i = posicao.queryPos(queries[i].i - 1) + 1;			
		}
	}	

	posicao.clear();

	for(int i=0; i<n+q; i++){
		if(queries[i].t == 0){
			posicao.update(queries[i].i, 1);
			segtree.update(queries[i].i, queries[i].x);			
		}else{
			int pos = segtree.query(1, queries[i].i, v[queries[i].i] + queries[i].x);
			
			printf("%d\n", posicao.querySum(pos));
		}
	}	
	
		
	return 0;
}
