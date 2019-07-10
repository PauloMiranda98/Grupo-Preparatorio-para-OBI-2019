#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 510;

int dist[MAXN][MAXN];

int n, m;


int main() {
	memset(dist, 0x3f, sizeof(dist));
	cin >> n >> m;
	
	for(int i=1; i<=n; i++)
		dist[i][i] = 0;
	
	for(int i=0; i<m; i++){
		int a, b, w;
		cin >> a >> b >> w;
		dist[a][b] = w;
		dist[b][a] = w;
	}
	
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	int ans = INF;
	for(int i=1; i<=n; i++){
		//Para cada local de sair, vamos pegar o maximo
		int mx = 0;
		for(int j=1; j<=n; j++){
			mx= max(mx, dist[i][j]);			
		}
		//Dentre todos os máximos, vamos pegar o que resulta a menor resposta
		ans = min(ans, mx);
	}
	
	cout << ans << endl;
	
	return 0;
}
