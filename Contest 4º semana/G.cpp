#include <iostream>

using namespace std;

typedef long long int ll; // Definindo ll como long long int para facilitar

ll fib(int n){
	if(n <= 1)
		return 1L;

	return fib(n-1) + fib(n-2);
}

int main() {
	int n;
	cin >> n;
	
	cout << fib(n) << "\n";

	return 0;
}

