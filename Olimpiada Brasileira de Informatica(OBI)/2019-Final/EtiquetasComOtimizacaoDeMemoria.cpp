#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const int MAXN = 10010;
int v[MAXN];
int dp[2][MAXN];
int n, k, c;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	cin >> n >> k >> c;
	
	for(int i=0; i<n; i++)
		cin >> v[i];

	dp[0][n] = 0;
	dp[1][n] = -INF;

	for(int i=n-1; i>=0; i--)
		dp[0][i] = dp[0][i+1] + v[i]; 
	
	for(int f=1; f<=k; f++){
		for(int i=n-1; i>=0; i--){
			if(i+c <= n){
				dp[f&1][i] = (dp[f&1][i+1] != -INF) ? (dp[f&1][i+1] + v[i]) : -INF;
				dp[f&1][i] = max(dp[(f&1)^1][i+c], dp[f&1][i]);			
			}else{
				dp[f&1][i] = (dp[f&1][i+1] != -INF)? (dp[f&1][i+1] + v[i]) : -INF;								
			}
		}
		dp[0][n] = -INF;
	}
				
	cout << dp[k&1][0] << endl;
	return 0;
}

/*
Entrada:
12 2 3
1 22 4 -8 9 2 10 -1 5 5 32 -11

Saída:
58
*/ 
 
