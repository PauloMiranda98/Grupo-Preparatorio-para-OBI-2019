#include <bits/stdc++.h>

using namespace std;

int v[100010];
int n, k;

int main() {	
	cin >> n;
		
	for(int i=0; i<n; i++)
		cin >> v[i];
	
	cin >> k;
	
	for(int i=0; i<n-1; i++){
		//Pegar a posição do elemento k - v[i]
		int pos = lower_bound(v+i+1, v+n, k - v[i]) - v;

		//Verifico se é valida
		if( (pos < n) and (v[i]+v[pos] == k) ){
			cout << v[i] << " " << v[pos] << endl;
			return 0;
		}
	}
	
	return 0;
}
