#include <bits/stdc++.h>

using namespace std;

bool v[3];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	
	v[a%3] = true;
	
	if( v[b%3] )
		v[(b+1)%3] = true;
	else
		v[b%3] = true;
		
	for(int i=0; i<3; i++)
		if(!v[i])
			cout << i << endl;

	return 0;
}
