#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 1010;

bool mat[MAXN][MAXN];
int n, m;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	cin >> n >> m;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			char c;
			cin >> c;
			if(c == '#')
				mat[i][j] = true;
		}
	}

	int cont = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			//Verifica se é terra e alguem adjacente é mar
			if(mat[i][j] and (!mat[i][j-1] or !mat[i][j+1] or !mat[i-1][j] or !mat[i+1][j]) )
				cont++;
		}
	}
	
	cout << cont << endl;
	
	return 0;
}
