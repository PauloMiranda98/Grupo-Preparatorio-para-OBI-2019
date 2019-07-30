#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int NBIT = 100010;

ll tree[NBIT];

//Retorna a soma de 1 até i	
ll query(int i){	
	ll s = 0;
	while(i > 0){
		s += tree[i];
		i -= (i & -i);
	}		
	return s;
}

//Incrementa a posição i com value
void update(int i, ll value){				
	while(i < NBIT){ 
		tree[i] += value;
		i += (i & -i);
	}
}

ll v[NBIT];
int n, q;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	cin >> n >> q;
	
	for(int i=1; i<=n; i++){
		cin >> v[i];
		update(i, v[i]);	
	}
	while(q--){
		int op, k;
		ll p;
		cin >> op;
		if(op == 0){
			cin >> k >> p;
			update(k, p - v[k]);
			v[k] = p;
		}else{
			cin >> k;
			cout << query(k) << endl;
		}
	}

	return 0;
}
