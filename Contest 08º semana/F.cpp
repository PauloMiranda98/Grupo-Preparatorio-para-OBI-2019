#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	
	//ordenar a < b < c;
	
	if(b < a)
		swap(a, b);
	if(c < a)
		swap(a, c);
	if(c < b)
		swap(b, c);

	//Algum vertice tem 90 grau
	if(a+b <= c)
		cout << "n" << endl;
	else if( (c*c) == (a*a + b*b) )
		cout << 'r' << endl;		
	else if((c*c) > (a*a + b*b))
		cout << "o" << endl;
	else
		cout << "a" << endl;
		
	return 0;
}
