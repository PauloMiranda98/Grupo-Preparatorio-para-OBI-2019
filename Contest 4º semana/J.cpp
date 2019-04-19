#include <iostream>
using namespace std;

//Complexidade O(2^n)
long long int hanoi(int n){
	if(n == 0)
		return 0;
		
	return hanoi(n-1) + 1LL + hanoi(n-1);
}

//Complexidade O(n)
long long int hanoi_rapido(int n){
	if(n == 0)
		return 0;
		
	return 2LL*hanoi_rapido(n-1) + 1LL;
}

//Complexidade O(1)
long long int hanoi_muito_rapido(int n){
	return (1LL<<n) - 1LL;		
}

int main() {
	int caso = 1;
	while(true){
		int n;
		cin >> n;

		if(n == 0)
			break;
		cout << "Teste " << caso << "\n";
		cout << hanoi_rapido(n) << "\n";
		caso++;
	}

	return 0;
}
