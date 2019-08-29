#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 1010;
ll bit[MAXN][MAXN];

void update(int a, int b, ll value){
	for(int i=a; i<MAXN; i += i&-i)
		for(int j=b; j<MAXN; j += j&-j)
		bit[i][j] = max(bit[i][j], value);
}

ll query(int a, int b){
	ll mx = 0;
	for(int i=a; i>0; i -= i&-i)
		for(int j=b; j>0; j -= j&-j)
		mx = max(bit[i][j], mx);
		
	return mx;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--){
		memset(bit, 0, sizeof(bit));

		int n;
		cin >> n;
		
		ll mx = 0;
		for(int i=0; i<n; i++){
			int a, b;
			cin >> a >> b;
			
			ll x = query(a, b);
			update(a, b, x+1LL);

			mx = max(mx, x+1LL);
		}
		
		cout << mx << '\n';
	}

	return 0;
}
