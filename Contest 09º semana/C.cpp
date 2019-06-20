#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

struct A{
	int pos;
	int val;
};

A v[MAXN];
bool mark[MAXN];
int n;

bool comp(A a, A b){
	return a.val > b.val;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> v[i].val;
		v[i].pos = i+1;
	}
	
	int ans = 0;
	
	int total = 0; //Conta a quantidade de grupos
	sort(v, v+n, comp);

	int i = 0;
	while(i<n){
		int j=i;
		
		//inserindo quem tem valor v[i].val
		while(j<n and (v[i].val == v[j].val)){
			
			//Junta dois grupos
			if( mark[v[j].pos-1] and mark[v[j].pos+1])
				total--;
			//Cria um grupo novo
			else if( !mark[v[j].pos-1] and !mark[v[j].pos+1])
				total++;
			
			mark[v[j].pos] = true;
			j++;
		}
		
		//Verificar se é a melhor resposta
		ans = max(total, ans);
		i = j;	
	}
	
	//Quantidade de grupo acima da melhor linha + parte de baixo
	cout << ans+1 << "\n";
			
	return 0;
}
