#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 1010;

int f[MAXN];
int a[MAXN];

int n, m, k;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	cin >> n >> k >> m;
	
	for(int i=1; i<=n; i++){
		cin >> a[i];
		a[i] %= m;

		//Evitar que fique negativo
		if(a[i] < 0)
			a[i]+=m;
	}
	
	for(int i=1; i<=n; i++){
		cin >> f[i];
		f[i] %= m;
		
		//Evitar que fique negativo
		if(f[i] < 0)
			f[i]+=m;
	}
	
	for(int i=n+1; i<=k; i++){
		f[i] = 0;
		for(int j=1; j<=n; j++){
			//ll para evitar overflow
			f[i] = (f[i] + ll(a[j])*ll(f[i-j]))%m;

			//Evitar que fique negativo
			if(f[i] < 0)
				f[i] += m;
		}
	}
	
	cout << f[k] << endl;
	return 0;
}
