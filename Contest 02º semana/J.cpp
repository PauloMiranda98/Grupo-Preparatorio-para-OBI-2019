#include <iostream>

using namespace std;

int main() {
	int menor;
	int n, atual;
	cin >> n >> atual;
	
	menor = atual;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		atual += x;
		
		menor = min(menor, atual);
		//A função min retorna o menor valor entre os dois.
	}

	cout << menor << "\n";

	return 0;
}
