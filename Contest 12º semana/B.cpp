#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

const int MAXN = 1010;
int mat[MAXN][MAXN];
bool vis[MAXN][MAXN];

int n, m;

int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

//Verificar se posso ir para um local na matriz
bool pode(int i, int j){
	if( (i>=1) and (i<=n) and (j>=1) and (j<=m) and (!vis[i][j]) )
		return true;
	return false;
}

int ans;

void dfs(int i, int j, int d){
	vis[i][j] = true;

	if(mat[i][j] == 3){
		ans = d;
		return;
	}

	if(mat[i][j] == 0)
		return;
		
	//Olhar para todas os valores adjacentes
	for(int k=0; k<4; k++){
		int to_i = i + dx[k];
		int to_j = j + dy[k];
		
		if(pode(to_i, to_j))
			dfs(to_i, to_j, d+1);
	}
}

int main() {
	cin >> n >> m;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> mat[i][j];		
		}
	}

	//Procurar por onde começar
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(mat[i][j] == 2){
				dfs(i, j, 1);

				cout << ans << endl;
				return 0;				
			}		
		}
	}
	
	return 0;		
}
