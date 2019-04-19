#include <iostream>

using namespace std;
	
int main() {
	int a, b, c;
	int h, l;
	
	cin >> a >> b >> c;
	cin >> h >> l;
	
	//Vamos deixar o menor valor em A e o segundo menor em B
	if(b < a)
		swap(a, b);
	if(c < a)
		swap(a, c);
	if(c < b)
		swap(b, c);

	//Vamos deixar o menor valor em H
	if(l < h)
		swap(l, h);
	
	//Deixamos em ordem pois facilita na hora de comparar
	if( (a <= h) and (b <=l ) )
		cout << "S" << "\n";
	else
		cout << "N" << "\n";
		
	return 0;
}
