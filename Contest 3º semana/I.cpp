#include <iostream>

using namespace std;

int m[60][60];

int main() {
	int n, q;
	cin >> n;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> m[i][j];
		}
	}
	
	cin >> q;
	
	int colheta = 0;
	
	for(int k=0; k<q; k++){
		int li, ci, lf, cf;
		
		cin >> li >> ci >> lf >> cf;
		
		for(int i=li; i<=lf; i++){
			for(int j=ci; j<=cf; j++){
				colheta += m[i][j];
				m[i][j] = 0;
			}
		} 
	}
	
	cout << colheta << "\n";

	return 0;
}
