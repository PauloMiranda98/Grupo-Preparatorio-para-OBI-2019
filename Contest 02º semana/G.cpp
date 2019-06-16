#include <iostream>

using namespace std;

int main() {
	int n;
	int d0=0, d1=0, d2=0, d3=0, d4=0, d5=0, d6=0, d7=0, d8=0, d9=0;
	cin >> n;
	
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		
		while(x != 0){
			//Pegar o último dígito
			int digito = x%10;
			if(digito == 0)
				d0++;
			else if(digito == 1)
				d1++;
			else if(digito == 2)
				d2++;
			else if(digito == 3)
				d3++;
			else if(digito == 4)
				d4++;
			else if(digito == 5)
				d5++;
			else if(digito == 6)
				d6++;
			else if(digito == 7)
				d7++;
			else if(digito == 8)
				d8++;
			else
				d9++;
			//Tirar o último dígito
			x = x/10;
		}
	}

	cout << "0 - " << d0 << "\n";
	cout << "1 - " << d1 << "\n";
	cout << "2 - " << d2 << "\n";
	cout << "3 - " << d3 << "\n";
	cout << "4 - " << d4 << "\n";
	cout << "5 - " << d5 << "\n";
	cout << "6 - " << d6 << "\n";
	cout << "7 - " << d7 << "\n";
	cout << "8 - " << d8 << "\n";
	cout << "9 - " << d9 << "\n";

	return 0;
}
