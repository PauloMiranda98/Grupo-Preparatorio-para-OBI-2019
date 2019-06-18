#include <bits/stdc++.h>

using namespace std;

int n;

int sqr(int a){
	
	return a*a;
}

int main() {	
	cin >> n;
	
	int ans = 0;
	
	for(int i=0; i<n; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ans += sqr(x1-x2) + sqr(y1-y2);
	}
	
	cout << ans << endl;

	return 0;
}
