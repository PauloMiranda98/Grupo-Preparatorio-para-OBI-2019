#include <bits/stdc++.h>

using namespace std;
int n;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	cin >> n;

	int d=0, x=0;
	for(int i=0; i<n; i++){
		int a, b;
		cin >> a >> b;
		if( (a+1)%5 == b or (a+2)%5 == b)
			d++;
		else
			x++;
	}

	if(d > x)
		cout << "dario" << endl;
	else
		cout << "xerxes" << endl;

	return 0;
}
