#include <iostream>
#include <algorithm>

using namespace std;

//resolve o mesmo problema para qualquer base e qualquer multiplo

int restoDivisao(string s, int multiplo, int base){
	int acu = 0;
	int potencia = 1;
	
	//A string é revertida para não precisar olhar de tras para frente
	reverse(s.begin(), s.end());
	
	for(char c: s){		
		acu = (acu + (c-'0')*potencia) % multiplo; 
		potencia = (potencia*base) % multiplo;
		
		//A vantagem de usar modulo é que o numero não cresce, fica limitado entre -multiplo < acu < multiplo;
		//Em caso de multiplos muito grandes, cuidado com overflow
	}
	
	return acu % multiplo;
}


int main() {
	
	string s;
	cin >> s;
	
	cout << restoDivisao(s, 3, 10) << "\n";
	
	return 0;	
}
