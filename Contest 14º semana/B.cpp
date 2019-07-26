#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1010;

int v[MAXN];
int n;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	cin >> n;
	for(int i=0; i<n; i++)
		cin >> v[i];
	if(n == 1){
		
		cout << 1 << endl;
		return 0;
	}
	
	int cont = 1;
	int d = v[1] - v[0];
	for(int i=2; i<n; i++){
		if(v[i]-v[i-1] != d){
			d = v[i]-v[i-1];
			cont++;
		}
	}
	
	cout << cont << endl;

	return 0;
}
