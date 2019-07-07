#include <iostream>

using namespace std;
const int INF = 0x3f3f3f3f;

int matriz[102][102];
bool acessado[102][102];
int n;

int dfs(int x, int y, int ant){
	int cont = 1;

	if(acessado[x][y] or (x>n) or (y>n) or (x<1) or (y<1) or (matriz[x][y] < ant) )
		return 0;
		
	acessado[x][y] = true;
	cont += dfs(x, y-1, matriz[x][y]);			
	cont += dfs(x, y+1, matriz[x][y]);
	cont += dfs(x-1, y, matriz[x][y]);
	cont += dfs(x+1, y, matriz[x][y]);	

	return cont;
}

int main(){	
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	int x, y;
	cin >> x >> y;
	
	for(int i=1; i <=n; i++){
		for(int j=1; j <=n; j++){
			cin >> matriz[i][j];			
		}
	}	
	
	cout << dfs(x, y, 0) << endl; 
														 			   				
	return 0;
	
}   
