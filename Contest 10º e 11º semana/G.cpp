#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int MAXN = 110;

int mat[MAXN][MAXN];
int dp[MAXN][MAXN];

int n;

//Disponível de i..j
int solve(int i, int j){
	if(i == j)
		return mat[0][i];	
	
	if(dp[i][j] != -1)
		return dp[i][j];
		
	//Calcula em qual linha tá
	int l = j - i;
	int sum = 0;
	
	for(int k=i; k<=j; k++)
		sum += mat[l][k];

	//Escolhe qual não será escolhido o i ou o j
	return dp[i][j] = sum + min( solve(i+1, j), solve(i, j-1) );
}

int main() {
	memset(dp, -1, sizeof(dp));
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> mat[i][j];
		}
	}
	
	//Começa da última linha e vai subindo	
	cout << solve(0, n-1) << endl;

	return 0;
}
