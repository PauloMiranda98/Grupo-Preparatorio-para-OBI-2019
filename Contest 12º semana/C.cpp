#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

const int MAXN = 110;
const int INF = 0x3f3f3f3f;

int mat[MAXN][MAXN];
int d[MAXN][MAXN];

int n;

int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

//Verificar se posso ir para um local na matriz
bool pode(int i, int j){
	if( (i>=1) and (i<=n) and (j>=1) and (j<=n) )
		return true;
	return false;
}

void bfs_01(int s_i, int s_j){
	memset(d, 0x3f, sizeof(d));
	d[s_i][s_j] = 0;
	deque<pii> q;
	q.push_front(pii(s_i, s_j));
	
	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop_front();

		//Olhar para todas os valores adjacentes
		for(int k=0; k<4; k++){
			int to_i = i + dx[k];
			int to_j = j + dy[k];

			if(pode(to_i, to_j)){
				int w = mat[to_i][to_j];
				
				if (d[i][j] + w < d[to_i][to_j]) {
					d[to_i][to_j] = d[i][j] + w;
					if (w == 1)
						q.push_back(pii(to_i, to_j));
					else
						q.push_front(pii(to_i, to_j));
				}
			}
		}
	}	
}

int main() {	
	cin >> n;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> mat[i][j];		
		}
	}
	
	//Poderia usar o algoritmo de Dijkstra mas para esse problema podemos usar uma BFS01
	bfs_01(1, 1);
	
	cout << d[n][n] << endl;

	return 0;	
}
