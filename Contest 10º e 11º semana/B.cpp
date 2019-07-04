#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 1000010;

int v[2*MAXN];

int main() {
	int n, d;
	cin >> n >> d;
	
	for(int i=0; i<n; i++){
		cin >> v[i];		
		//Copiar vetor para o final
		v[n+i] = v[i];
	}
	
	int i=0, j=0;
	int sum = 0;
	int cont = 0;

	//Two-pointers
	while(i<n){
		//(j-i < n) -> garantir que não pegue elementos repetidos, no caso da soma de todos os elementos ser menor que d
		while( (j-i < n) and (sum + v[j] <= d) ){
			sum += v[j];
			j++;
		}
		if(sum == d)
			cont++;
		
		sum -= v[i];
		i++;
	}
	
	cout << cont << endl;

	return 0;
}
