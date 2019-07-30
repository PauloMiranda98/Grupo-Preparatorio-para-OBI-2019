#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f;

//Guarda a melhor forma de dividir o intervalo de i..j.
//Se i <= j então dividir(i..j)
//senao dividir(j..(n-1),0..i)
int dp[210][210];

//Guarda a soma de intervalo de i..j.
//Se i <= j então soma(i..j)
//senao soma(j..(n-1)) + soma(0..i)
int sum[210][210];
int v[210];
int n;
double f;

int solve(int i, int j){
	if(i == j)
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	dp[i][j] = INF;
	for(int k=i; k != j; k=(k+1)%n)
		dp[i][j] = min(dp[i][j], solve(i, k) + solve((k+1)%n, j) + max(sum[i][k], sum[(k+1)%n][j]));	
	
	return dp[i][j];
}

int main(){	
	memset(dp, -1, sizeof(dp));

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	cin >> n >> f;
	
	for(int i=0; i<n; i++)
		cin >> v[i];
		
	//Calculando a soma de um intervalo
	for(int i=0; i<n; i++){
		sum[i][i] = v[i];
		for(int k=1; k<n; k++){
			sum[i][(i+k)%n] = sum[i][(i+k-1)%n] + v[(i+k)%n];
		}
	}

	int ans = INF;

	//Testanto as forma de quebrar o primeiro círculo
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			ans = min(ans, solve(i, j) + solve((j+1)%n, (n+i-1)%n) + max(sum[i][j], sum[(j+1)%n][(n+i-1)%n]));	
		}
	}

	cout << fixed << setprecision(2) << ans*f << endl;
	
	return 0;
}
