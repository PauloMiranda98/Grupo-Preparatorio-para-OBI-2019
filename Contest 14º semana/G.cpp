#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1000000007;
const int MAXN = 10010;
	
int dp[MAXN];

int solve(int n){
	if(n < 0)
		return 0;
		
	if(n == 0)
		return 1;
			
	if(dp[n] != -1)
		return dp[n];
	
	//cuidade na hora no %MOD
	//Sendo A, B e C entre 0 e MOD-1
	//A+B+C e 4*A pode dar overflow
	//Solução
	//F(n) = F(n-1) + 4*F(n-2) + 2*F(n-3)
	
	return dp[n] = (solve(n-1) + ((4LL*(ll)solve(n-2))%MOD + (2*solve(n-3))%MOD)%MOD)%MOD;
}

int main(){	
	memset(dp, -1, sizeof(dp));

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int n;
	cin >> n;
	
	cout << solve(n) << endl;
	
	return 0;
}
