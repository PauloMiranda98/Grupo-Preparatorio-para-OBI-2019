#include <iostream>
#include <algorithm>
using namespace std;


int v[10];

int main() {

	for(int i=0; i<8; i++){
		cin >> v[i];
	}
	
	//Solução para treinar next_permutation
	//dava para fazer com uma complexidade menor

	sort(v, v+8);
	
	do{
		bool valido = true;

		for(int i=1; i<8; i++)
			if(v[i] == v[i-1])
				valido = false;

		if(valido){
			cout << "S" << "\n";
			return 0;
		}
				
	}while(next_permutation(v, v+8));
			
	cout << "N" << "\n";
	
	return 0;
}
