#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 1000000007;

int dp[1010][1010];
int n, k;

//solve(posição do bit atual, quantidade de uns consecutivos)
int solve(int i, int q){
	//Quantidade de 1's igual a k
	if(q == k)
		return 0;

	//chegou na última posição
	if(i == n)
		return 1;	
	
	if(dp[i][q] != -1)
		return dp[i][q];
		
	//solve(i+1, 0) -> Escolheu 0
	//solve(i+1, q+1) -> Escolheu 1	
	return dp[i][q] = (solve(i+1, 0) + solve(i+1, q+1))%MOD;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n >> k;
	
	cout << solve(0, 0) << endl; 

	return 0;
}
