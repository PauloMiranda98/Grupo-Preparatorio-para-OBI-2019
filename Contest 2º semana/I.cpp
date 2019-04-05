#include <iostream>

using namespace std;

int main() {
	int resultado = 0;
	int n;
	cin >> n;
	
	for(int i=1; i<=n; i++){
		int l, c;
		cin >> l >> c;
		
		if(l > c){
			resultado += c;
		}
	}
	
	cout << resultado << "\n";

	return 0;
}
