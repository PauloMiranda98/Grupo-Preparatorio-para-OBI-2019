#include <iostream>

using namespace std;
	
int main() {
	int n, x, y, z;
	cin >> n;
	cin >> x >> y >> z;
	
	
	//Vamos ordenar x <= y <= z
	if(y < x)
		swap(x, y);
	if(z < x)
		swap(x, z);
	if(z < y)
		swap(y, z);
		
	int cont = 0;
	
	if(n >= x){
		cont++;
		n -= x;
	}

	if(n >= y){
		cont++;
		n -= y;
	}

	if(n >= z){
		cont++;
		n -= z;
	}
	
	cout << cont << "\n";

	return 0;
}
