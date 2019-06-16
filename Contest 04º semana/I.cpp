#include <iostream>

using namespace std;


int soma_vetor(int n, int v[]){
	int soma = 0;
	
	for(int i=0; i<n; i++)
		soma += v[i];
	
	return soma;
}

int v[100100];

int main(){

    int n;
    cin >> n;

    for(int i=0;i<n;i++)
        cin >> v[i];

    cout << soma_vetor(n,v) << "\n";
}
