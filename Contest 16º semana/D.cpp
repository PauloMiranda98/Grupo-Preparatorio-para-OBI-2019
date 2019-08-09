#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;
typedef long long ll;

int tree[MAXN];
int v[MAXN];
int n;

void update(int i, int value){
	for(int x=i; x<=n; x+=(x&-x))
		tree[x] += value;
}

int query(int i){
	int sum = 0;
	for(int x=i; x>0; x-=(x&-x))
		sum += tree[x];
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	while(true){
		cin >> n;
		if(n == 0)
			break;
			
		//Limpando a BIT
		for(int i=1; i<=n; i++)
			tree[i] = 0;

		for(int i=1; i<=n; i++)
			cin >> v[i];
			
		//Ideia: contar a quantidade de elementos menores que v[i] e acumular, olhando de trás para frente.
		//Se a quantidade for impar o Marcelo ganha, caso contrário perde.
		ll cont = 0;
		for(int i=n; i>=1; i--){
			cont += query(v[i]);
			update(v[i], 1);
		}
		
		if(cont%2 == 1)
			cout << "Marcelo" << endl;
		else
			cout << "Carlos" << endl;
	}
	return 0;
}
