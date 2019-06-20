#include <bits/stdc++.h>

using namespace std;


int main() {
	//Existem maneiras mais efientes, mas para essa entrada não é necessário.
	
	int n, cont = 0;	
	cin >> n;
	
	while(n >= 100){
		n -= 100;
		cont++;
	}

	while(n >= 50){
		n -= 50;
		cont++;
	}

	while(n >= 25){
		n-= 25;
		cont++;
	}

	while(n >= 10){
		n-= 10;
		cont++;
	}

	while(n >= 5){
		n-= 5;
		cont++;
	}

	while(n >= 1){
		n-= 1;
		cont++;
	}
	
	cout << cont << "\n";

	return 0;
}
