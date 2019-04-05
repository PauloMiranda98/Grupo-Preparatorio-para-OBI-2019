#include <iostream>

using namespace std;

int main() {
	int n;
	int a, b, c; //Os 3 ultimos
	int resultado = 0;
	
	cin >> n;
	
	if(n < 3){
		cout << 0 << "\n";
	}else{
		//Ler os dois primeiro valores
		cin >> a;		
		cin >> b;
		
		//Ler do 3º para frente
		for(int i=3; i<=n; i++){
			cin >> c;

			if( (a == 1) and (b == 0) and (c == 0) ){
				resultado++;
			}
			a = b;
			b = c;
		}
		
		cout << resultado << "\n";
	}
	return 0;
}
