#include <iostream>
#include <algorithm>
using namespace std;

int v[100010];

int main() {
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	
	sort(v, v+n);
	
	for(int i=0; i<n; i++){
		if(i > 0)
			cout << " ";
		cout << v[i];
	}
	
	cout << "\n";

	return 0;
}

