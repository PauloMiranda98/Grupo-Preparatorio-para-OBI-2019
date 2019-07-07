#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

//Kadane: O(N)
ll kadane(vector<int> v){
	
	ll ans = 0LL, bigger = 0LL;
	
	for(int i=0; i < int(v.size()); i++){
		bigger = max(0LL, bigger + ll(v[i]));		
		ans = max(ans, bigger);
	}
	
	return ans;
}

//Circular Kadane: O(N)
ll circularKadane(vector<int> v){
	ll ans1 = kadane(v);
	
	ll sum = 0LL;
	for(int i=0; i < int(v.size()); i++){
		sum += ll(v[i]);
		v[i] = -v[i];
	}
	
	ll ans2 = sum + kadane(v);

	return max(ans1, ans2);
	
}

vector<int> v;
int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	
	cin >> n;
	v.resize(n);
	
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	
	cout << circularKadane(v) << endl;
					
	return 0;
	
}
