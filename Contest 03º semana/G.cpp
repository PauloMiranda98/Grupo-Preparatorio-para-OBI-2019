#include <iostream>
#include <string.h>

using namespace std;

char v[60];

int main() {
	cin >> v;
	
	int i = 0;
	int j = strlen(v)-1;
	//A função strlen pegar o tamanho da string no vetor de char.
	
	bool engracada = true;
	
	while(i <=j ){
		//procurar a proxima vogal
		while( (i<=j) and (v[i]!='a') and (v[i]!='e') and (v[i]!='i') and (v[i]!='o') and (v[i]!='u') ){
			i++;
		}

		//procurar a proxima vogal
		while( (j>=i) and (v[j]!='a') and (v[j]!='e') and (v[j]!='i') and (v[j]!='o') and (v[j]!='u') ){
			j--;
		}
		
		//Se não encontrar, paro a busca
		if(i > j)
			break;
			
		//Após encontrar as duas vogais, verifico se é diferente
		if( v[i] != v[j])
			engracada = false;
			
		i++;
		j--;
	}
	
	if(engracada == true)
		cout << "S" << "\n";
	else
		cout << "N" << "\n";
		
	return 0;
}
