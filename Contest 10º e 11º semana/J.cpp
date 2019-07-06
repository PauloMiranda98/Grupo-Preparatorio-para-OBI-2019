#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 2010;

ll dp[MAXN][MAXN];

int peso[MAXN];
int ganho[MAXN];

int n, s;

//Solve(item analisado,  o que ele ainda pode comer)
ll solve(int i, int falta){
	if(i == n)
		return 0;

	if(dp[i][falta] != -1LL)
		return dp[i][falta];
		
	//Verifica se posso escolher o item
	if(peso[i] <= falta)		
		return dp[i][falta] = max(ganho[i] + solve(i+1, falta - peso[i]), solve(i+1, falta)); //Pego a melhor resposta entre escolher ou não o item
	else	
		return dp[i][falta] = solve(i+1, falta); //Não posso escolher
}

int main() {
	memset(dp, -1, sizeof(dp));
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	cin >> s >> n;
	
	for(int i=0; i<n; i++){
		cin >> peso[i];
		cin >> ganho[i];
	}
	
	cout << solve(0, s) << endl;

	return 0;
}
