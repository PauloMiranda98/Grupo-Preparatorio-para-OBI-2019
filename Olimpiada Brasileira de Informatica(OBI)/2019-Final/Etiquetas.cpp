#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const int MAXN = 10010;
int v[MAXN];
int dp[MAXN][MAXN];
int n, k, c;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	cin >> n >> k >> c;
	
	for(int i=0; i<n; i++){
		cin >> v[i];
	}

	dp[n][0] = 0;
	for(int f=1; f<=k; f++){
		dp[n][f] = -INF;
	}

	for(int i=n-1; i>=0; i--){
		for(int f=0; f<=k; f++){
			if(i+c <= n){
				//dp[i][f] = max(dp[i+1][f] + v[i], dp[i+c][f-1]);
				dp[i][f] = (dp[i+1][f] != -INF) ? (dp[i+1][f] + v[i]) : -INF;
				if(f > 0)
					dp[i][f] = max(dp[i+c][f-1], dp[i][f]);			
			}else{
				//dp[i][f] = dp[i+1][f] + v[i];
				dp[i][f] = (dp[i+1][f] != -INF)? (dp[i+1][f] + v[i]) : -INF;								
			}
		}
	}
				
	cout << dp[0][k] << endl;

	return 0;
}

/*
Entrada:
12 2 3
1 22 4 -8 9 2 10 -1 5 5 32 -11

Saída:
58
*/ 
 
