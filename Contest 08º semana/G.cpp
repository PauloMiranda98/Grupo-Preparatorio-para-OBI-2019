#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	
	ll n;
	cin >> n;
		
	if( ((n&(n+1)) == 0) and (n != 0) ){
		cout << "S" << endl;
	}else{
		cout << "N" << endl;		
	}

	return 0;
}
