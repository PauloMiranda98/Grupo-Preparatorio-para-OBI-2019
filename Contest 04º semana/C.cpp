#include <iostream>

using namespace std;

int main() {
	int l, c;
	cin >> l >> c;
	
	cout << l*c + (l-1)*(c-1) << "\n"; 
	cout << (l-1)*2 + (c-1)*2 << "\n"; 

	return 0;
}
