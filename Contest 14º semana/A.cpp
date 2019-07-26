#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int l, c;
	cin >> l >> c;
	
	if(l%2 == c%2)
		cout << 1 << endl;
	else
		cout << 0 << endl;
		
	return 0;
}
