#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int qtd[6];
int val[6] = {2, 5, 10, 20, 50, 100};

ll dp[6][5010];

//Solve(Moeda atual analisada, total restante)
ll solve(int i, int s){
	if(s == 0)
		return 1LL;
	if(i == 6)
		return 0LL;
	if(dp[i][s] != -1LL)
		return dp[i][s];
	ll ans = 0;

	//Tenta colocar todas as possíveis forma para uma determinada moeda
	for(int k=0; k<=qtd[i]; k++){
		if(k*val[i] <= s)
			ans += solve(i+1, s - k * val[i]);
	}
	
	return dp[i][s] = ans;
	
}

int main() {
	memset(dp, -1, sizeof(dp));
	int s;
	cin >> s;
	
	for(int i=0; i<6; i++)
		cin >> qtd[i];

	cout << solve(0, s) << endl;
	
	return 0;
}
