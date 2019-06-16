#include <iostream>

using namespace std;

int main() {
	int h, p, f, d;
	cin >> h >> p >> f >> d;
	
	while( (f != h) and (f != p)){
		f += d;
		
		if(f == 16)
			f = 0;
		if(f == -1)
			f = 15;
	}
	
	if(f == h)
		cout << "S" << "\n";
	else
		cout << "N" << "\n";

	return 0;
}
