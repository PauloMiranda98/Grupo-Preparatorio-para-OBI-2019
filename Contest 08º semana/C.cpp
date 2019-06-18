#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int n;
	int ans=0;
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
	
		ans |= x;		
	}
	
	cout << ans << "\n";
	
	return 0;
}
