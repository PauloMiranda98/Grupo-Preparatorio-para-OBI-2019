#include <iostream>
#include <algorithm>

using namespace std;

int vet[100010];
int vet2[100010];

int main(){

    int n;
    int cont = 0;

	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> vet[i];
		vet2[i] = vet[i];
	}

	sort(vet2, vet2+n);
	
	for(int i=0; i<n; i++){
		if(vet2[i] != vet[i])
			cont++;
	}
	
	cout << cont << endl;

	for(int i=0; i<n; i++){
		if(vet2[i] != vet[i])
			cout << vet2[i] << " ";
	}
	
	cout << "\n";
	
	return 0;
}
