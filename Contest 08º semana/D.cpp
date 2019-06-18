#include <bits/stdc++.h>

using namespace std;
	
int main() {
	
	int x0, y0, x1, y1; 
	int x2, y2, x3, y3; 
	
	cin >> x0 >> y0 >> x1 >> y1; 
	cin >> x2 >> y2 >> x3 >> y3; 

	int a, b, c, d;
	a = max(x0, x2);
	b = min(x1, x3);
	c = max(y0, y2);
	d = min(y1, y3);
	
	
	//Retangulo gerado pela intesecção: (a, c) e (b, d)
	//Falta apenas verificar se é válido
	if( (a<=b) and (c<=d) )
		cout << 1 << endl;
	else
		cout << 0 << endl;
		
	return 0;
}
