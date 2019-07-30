#include <bits/stdc++.h>

using namespace std;

char mat[110][110];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int l, c;
int x, y;

bool pode(int i, int j){
	if(i < 1 or i > l or j < 1 or j > c or mat[i][j]=='.')
		return false;
	return true;
}

void dfs(int i, int j){
	mat[i][j] = '.';
	x=i; 
	y=j;
	for(int k=0; k<4; k++){
		int nx = x + dx[k];
		int ny = y + dy[k];

		if(pode(nx, ny))
			dfs(nx, ny);
	}
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	cin >> l >> c;
	
	for(int i=1; i<=l; i++){
		for(int j=1; j<=c; j++){
			cin >> mat[i][j];
			if(mat[i][j] == 'o'){
				x = i;
				y = j;
			}				
		}
	}
	
	dfs(x, y);
	
	cout << x << " " << y << endl; 
	
	return 0;
}
