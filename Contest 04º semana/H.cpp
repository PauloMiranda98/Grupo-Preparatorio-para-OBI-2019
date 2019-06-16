#include <iostream>

using namespace std;


int f(int n){
	if(n == 1)
		return 0;
		
	if(n%2 == 0)
		return 1 + f(n/2);
	else
		return 1 + f(3*n + 1);	
}

int main() {
	int n;	
	cin >> n;
	
	cout << f(n) << "\n";

	return 0;
}
