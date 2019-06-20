#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	int ant = 0;
	ll sum = 0;
	
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		int mn = min(m-x, x);
		int mx = max(m-x, x);
		if(ant <= mn){
			sum += mn;
			ant = mn;
		}else if(ant <= mx){
			sum += mx;
			ant = mx;			
		}else{
			cout << -1 << endl;
			return 0;
		}
	}
	
	cout << sum << endl;

	return 0;
}
