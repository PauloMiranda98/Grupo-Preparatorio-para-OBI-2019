#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f;
const int MAXN = 100010;
	
int dp[MAXN][22];
int v[MAXN];
bool mark[MAXN];
int n, l, h;

//solve(posição atual, quantidade de valores marcados)
int solve(int i, int c){
	if(i == n){
		if(c < l or c > h)
			return -INF;
		else
			return 0;
	}
	
	if(dp[i][c] >= -INF)
		return dp[i][c];
	
	if(mark[i]){
		if(c < l) //Obrigado pegar o item
			dp[i][c] = solve(i+1, c+1) + v[i];
		else if( c == h) //Obrigado parar
			dp[i][c] = 0;
		else //Posso escolher entre continuar ou parar
			dp[i][c] = max(solve(i+1, c+1) + v[i], 0);
	}else{
		if(c < l) //Obrigado pegar o item
			dp[i][c] = solve(i+1, c) + v[i];
		else //Posso escolher entre continuar ou parar
			dp[i][c] = max(solve(i+1, c) + v[i], 0);
	}
	return dp[i][c];
}

int main(){	
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	for(int i=0; i<MAXN; i++)
		for(int j=0; j<22; j++)
			dp[i][j] = -INF - 2;
	
	cin >> n >> l >> h;
	
	for(int i=0; i<n; i++)
		cin >> v[i];
	for(int i=0; i<n; i++)
		cin >> mark[i];
	
	int ans = -INF;

	//Posso começar a pegar o item a partir de i
	for(int i=0; i<n; i++)
		ans = max(ans, solve(i, 0));
	
	cout << ans << endl;
	
	return 0;
}
