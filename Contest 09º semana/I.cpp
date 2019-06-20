#include <bits/stdc++.h>

using namespace std;

int v[100010];
int p[100010];
int n, m;

int main() {	
	cin >> n >> m;
		
	v[0] = 0;
	for(int i=1; i<n; i++)
		cin >> v[i];
	for(int i=0; i<n; i++)
		cin >> p[i];
		
	for(int i=0; i<m; i++){
		int ogro;
		cin >> ogro;
		//Pegar a próxima posição após o ogro
		int pos = upper_bound(v, v+n, ogro) - v;
		if(i > 0)
			cout << " ";
		cout << p[pos - 1];
	}
	
	cout << endl;
	
	return 0;
}
