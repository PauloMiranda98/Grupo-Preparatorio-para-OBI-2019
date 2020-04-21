#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 100010;
int n, m;

vector<int> adjC[MAXN];
vector<int> adjQ[MAXN];

int d1C, d2C; 
int c1, c2;
int d1Q, d2Q; 
int q1, q2;

int pC[MAXN];
int pQ[MAXN];

void dfs1C(int u, int p, int d){
	if(d > d1C){
		d1C = d;
		c1 = u; 
	}	
	for(int to: adjC[u]){
		if(to != p)
			dfs1C(to, u, d+1);
	}	
}

void dfs2C(int u, int p, int d){
	pC[u] = p;
	if(d > d2C){
		d2C = d;
		c2 = u; 
	}	
	for(int to: adjC[u]){
		if(to != p)
			dfs2C(to, u, d+1);
	}	
}

void dfs1Q(int u, int p, int d){
	if(d > d1Q){
		d1Q = d;
		q1 = u; 
	}	
	for(int to: adjQ[u]){
		if(to != p)
			dfs1Q(to, u, d+1);
	}	
}

void dfs2Q(int u, int p, int d){
	pQ[u] = p;
	if(d > d2Q){
		d2Q = d;
		q2 = u; 
	}	
	for(int to: adjQ[u]){
		if(to != p)
			dfs2Q(to, u, d+1);
	}	
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cin >> n >> m;
	for(int i=1; i<n; i++){
		int a, b;
		cin >> a >> b;
		adjC[a].push_back(b); 
		adjC[b].push_back(a); 
	}
	for(int i=1; i<m; i++){
		int a, b;
		cin >> a >> b;
		adjQ[a].push_back(b);
		adjQ[b].push_back(a);
	}
	dfs1C(1, -1, 0);
	dfs2C(c1, -1, 0);

	dfs1Q(1, -1, 0);
	dfs2Q(q1, -1, 0);
	
	int ansC = 0, ansQ = 0;
	if(d2C%2 == 0){
		int mC = q2
		for(int i=1; i<=(d2C/2); i++)
			mC = pC[mC];
		ansC = mC;
	}else{
		
	}
	if(d2Q%2 == 0){
		int mQ = c2;
		for(int i=1; i<=(d2Q/2); i++)
			mQ = pQ[mQ];
		
		cout << mC << " " << mQ << endl;
	}else{
		
	}
	return 0;
}

/*
Entrada: 
7 6
1 3
3 2
3 4
4 5
5 7
6 5
1 3
2 3
3 4
3 5
5 6

Saída:
4 3
 
* 

Entrada:
3 4
1 2
2 3
1 2
2 3 
3 4

Saída:
2 2
*/
