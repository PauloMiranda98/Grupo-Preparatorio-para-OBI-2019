#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;

bool visitado[15][15];

int dx[] = {0, 0, 2, -2};
int dy[] = {-2, 2, 0, 0};

int n, m;
int xe, ye;
int xs, ys;

bool pode(int x, int y){
	if(x<1 or x>n or y<1 or y>m or visitado[x][y])
		return false;
	return true;
}

int dfs(int x, int y){
	visitado[x][y] = true;
	if(x==xs and y==ys){
		visitado[x][y] = false;				
		return 1;
	}
	int ans = -INF;
	
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(pode(nx, ny)){
			ans = max(ans, dfs(nx, ny) + 2);
		}
				
	}	
	
	visitado[x][y] = false;				
	
	return ans;
}

int main() {
	cin >> n >> m;
	cin >> xe >> ye;
	cin >> xs >> ys;
	
	//O problema pode ser resumido a encontrar o maior caminho entre dois pontos andando de 2 em 2.
	cout << dfs(xe, ye) << endl;
	
	return 0;
}
