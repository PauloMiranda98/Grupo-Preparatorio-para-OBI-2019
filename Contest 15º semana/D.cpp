#include <bits/stdc++.h>

using namespace std;

int mat[20][20];
int v, h, d, k;

bool pode(int i, int j){
	if(i < 0 or i >= 15 or j < 0 or j>=15 )
		return false;
	return true;
}


int main() {
	
	for(int i=0; i<15; i++){
		for(int j=0; j<15; j++){
			cin >> mat[i][j];
		}
	}

	for(int i=0; i<15; i++){
		for(int j=0; j<15; j++){	
			if(mat[i][j] == 0)
				continue;

			//Diagonal principal
			d = 1;			
			k = 1;
			while(pode(i-k, j-k) and (mat[i][j] == mat[i-k][j-k]) ) k++;			
			d += k-1;
			k = 1;
			while(pode(i+k, j+k) and (mat[i][j] == mat[i+k][j+k]) ) k++;			
			d += k-1;
			if(d >= 5){
				cout << mat[i][j] << endl;
				return 0;
			}
			
			//Diagonal Secundária
			d = 1;
			k = 1;
			while(pode(i-k, j+k) and (mat[i][j] == mat[i-k][j+k]) ) k++;			
			d += k-1;
			k = 1;
			while(pode(i+k, j-k) and (mat[i][j] == mat[i+k][j-k]) ) k++;			
			d += k-1;
			if(d >= 5){
				cout << mat[i][j] << endl;
				return 0;
			}
			//Horizontal
			h = 1;
			k = 1;
			while(pode(i, j-k) and (mat[i][j] == mat[i][j-k]) ) k++;			
			h += k-1;
			k = 1;
			while(pode(i, j+k) and (mat[i][j] == mat[i][j+k]) ) k++;			
			h += k-1;
			if(h >= 5){
				cout << mat[i][j] << endl;
				return 0;
			}

			//Vertical
			v = 1;
			k = 1;
			while(pode(i-k, j) and (mat[i][j] == mat[i-k][j]) ) k++;			
			v += k-1;
			k = 1;
			while(pode(i+k, j) and (mat[i][j] == mat[i+k][j]) ) k++;			
			v += k-1;
			if(v >= 5){
				cout << mat[i][j] << endl;
				return 0;
			}

			
		}
	}
	
	cout << 0 << endl;

	
	return 0;
}
