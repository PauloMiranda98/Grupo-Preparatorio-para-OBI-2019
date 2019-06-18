#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int v[100010];
int n;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	ll sum = 0;
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> v[i];
		
		sum += v[i];
	}
	
	sort(v, v+n);
	
	int ans = n;
	
	//Para uma aresta pertencer ao polígono, o somatório do tamanho das outras arestas tem que ser maior.
	for(int i=n-1; (i>=0) and (v[i] >= (sum-v[i])); i--){
		ans--;
		sum -= v[i];
	}
	
	cout << ans << endl;
	
	return 0;
}
