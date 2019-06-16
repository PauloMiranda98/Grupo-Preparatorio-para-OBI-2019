#include <iostream>

using namespace std;

int main() {
	int ia, ib, fa, fb;
	cin >> ia >> ib >> fa >> fb;
	
	if( (ia == fa) and (ib == fb) )
		cout << 0 << "\n";
	else if( (ia == fa) and (ib != fb) )
		cout << 2 << "\n";
	else if( (ia != fa) and (ib == fb) )
		cout << 1 << "\n";
	else
		cout << 1 << "\n";		
	

	return 0;
}
