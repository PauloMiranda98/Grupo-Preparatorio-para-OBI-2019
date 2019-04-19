#include <iostream>

using namespace std;

typedef long long int ll; // Definindo ll como long long int para facilitar

ll fat(int n){
	if(n <= 1)
		return 1;

	return n*fat(n-1);
}

int main() {
	int n;
	cin >> n;
	
	cout << fat(n) << "\n";

	return 0;
}

