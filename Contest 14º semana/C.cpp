#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1010;
int sai[MAXN];
int entra[MAXN];

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int m, n;
	cin >> m >> n;

	int total1=0;
	for(int i=0; i<m; i++){
		int x, v, y;
		cin >> x >> v >> y;
		
		sai[x] += v;
		entra[y] += v;
		total1 += v;
	}
	
	int total2 = 0;
	for(int i=1; i<=n; i++){
		total2 += max(0, sai[i] - entra[i]);
	}
	
	if(total2 < total1)
		cout << "S" << endl;
	else
		cout << "N" << endl;
	cout << total2 << endl;
	
	return 0;
}
