#include <bits/stdc++.h>

using namespace std;

int mat[110][110];
int n;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> mat[i][j];

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int zero=0, um=0;
			if(mat[i][j]==9){
				if(mat[i-1][j-1]==0) zero++; else um++;					
				if(mat[i][j-1]==0) zero++; else um++;					
				if(mat[i-1][j]==0) zero++; else um++;					
				
				if(zero < um) mat[i][j] = 0; else mat[i][j] = 1;
			}
		}
	}
	
	cout << mat[n-1][n-1] << endl;
		
	return 0;
}
