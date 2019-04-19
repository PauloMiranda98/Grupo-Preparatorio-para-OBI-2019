#include <iostream>

using namespace std;

int v[100010];

int main() {
	int n;
	int total = 0;
	cin >> n;
	
	for(int i=1; i<=n; i++){
		cin >> v[i];
		total += v[i];
	}
	
	int acumulado = 0;
	
	for(int i=1; i<=n; i++){
		acumulado += v[i];
		if(acumulado*2 == total){
			cout << i << "\n";
			return 0;
		}
	}
	
	return 0;
}

