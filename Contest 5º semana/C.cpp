#include <iostream>
#include <algorithm>
using namespace std;

int v[10010];

int main() {
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	
	sort(v, v+n);
	
	bool pode = true;
	if(v[0] > 8)
		pode = false;
		
	for(int i=1; i<n; i++){
		if( (v[i] - v[i-1]) > 8)
			pode = false;
	}

	if(pode)
		cout << "S" << "\n";
	else
		cout << "N" << "\n";

	return 0;
}

