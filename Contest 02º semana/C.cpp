#include <iostream>

using namespace std;

int main() {
	int soma = 0;
	int dias = 0;
	int n;
	
	cin >> n;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		
		soma += x;
		dias++;
		
		if(soma >= 1000000){
			break;
		}
	}
	
	cout << dias << "\n";

	return 0;
}
