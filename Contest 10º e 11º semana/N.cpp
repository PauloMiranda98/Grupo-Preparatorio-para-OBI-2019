#include <bits/stdc++.h>

using namespace std;

bool dp[1010];
int n, m;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	cin >> n >> m;
		
	dp[0] = true;

	//Dp[i] == true -> Consigo formar o troco de i reais

	for(int i=0; i<n; i++){
		int moeda;
		cin >> moeda;
		
		for(int j=0; j+moeda <= m; j++){
			//Se é possível forma o j, então é possível forma j + moeda
			if(dp[j]) 
				dp[j+moeda] = true;
		}
	}
	
	if(dp[m])
		cout << 'S' << endl;
	else
		cout << 'N' << endl;

	return 0;
}
