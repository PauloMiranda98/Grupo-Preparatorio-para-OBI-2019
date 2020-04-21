#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int n, t;
	cin >> n >> t;
	
	if(t == 2){
		ll ans = 0;
		for(int i=1; i<=n; i++){
			for(int j=i+2; j<=n; j++){
				ans += (j-i-1);
			}
		}
		cout << ans << endl;
	}else if(t == 1){
		ll ans = 0;
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				ans += 2;
			}
		}
		cout << ans << endl;	
	}else{
		cout << n << endl;
	}
	return 0;
}
