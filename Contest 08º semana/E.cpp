#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll n;
	int cont = 0;
	
	cin >> n;
	
	while(n){
		cont += (n&1LL);

		n >>= 1;
	}
	
	cout << cont << "\n";

	return 0;
}
