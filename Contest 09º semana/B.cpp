#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 0x3f3f3f3f3f3f3f3fLL;

// Counting Inversions: O(N*log(N))
ll ci(vector<ll> &v){
	
	ll inv = 0LL;
	
	if(v.size() == 1) return 0;
	
	vector<ll> u1, u2;
	
	for(int i=0; i < int(v.size()/2); i++){
		u1.push_back(v[i]);
	}
	
	for(int i=v.size()/2; i < int(v.size()); i++){
	 	u2.push_back(v[i]);
	}
	
	inv += ci(u1);
	inv += ci(u2);
	
	u1.push_back(INF);
	u2.push_back(INF);
	
	int ini1=0, ini2=0;
	
	for(int i=0; i < int(v.size()); i++){
		
		if(u1[ini1] < u2[ini2]){			
			v[i] = u1[ini1];			
			ini1++;
		}else{			
			v[i] = u2[ini2];
			ini2++;
						
			inv += ll(u1.size() - ini1) - 1LL;
		}
	}
	
	return inv;
}

vector<ll> v;
int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	
	cin >> n;
	v.resize(n);
	
	for(int i=0; i<n; i++){
		ll x, y;
		cin >> x >> y;
		v[i] = x*x + y*y;
	}
	
	reverse(v.begin(), v.end());
	
	cout << ci(v) << endl;
					
	return 0;
	
}
