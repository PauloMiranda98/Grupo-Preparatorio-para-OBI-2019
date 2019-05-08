#include <iostream>

using namespace std;

typedef long long int ll;

ll n;
int k;

ll primos[50];

//qtd_divisores(primo atual, valor acumulado, qtd de primos atual)
ll qtd_divisores(int i, ll acu, int qtd_primos){
	if(acu > n)
		return 0;
	if(i == k){
		if(qtd_primos == 0)
			return 0;
			
		if(qtd_primos%2 == 0){
			return -n/acu;
		}else{
			return n/acu;
		}
	}
	
	return qtd_divisores(i+1, acu * primos[i], qtd_primos + 1) + qtd_divisores(i+1, acu, qtd_primos);
}

int main() {
	cin >> n >> k;
	
	for(int i=0; i<k; i++)
		cin >> primos[i];
		
	cout << n - qtd_divisores(0, 1, 0) << "\n";
		
	return 0;
}
