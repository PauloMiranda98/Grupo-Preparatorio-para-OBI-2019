#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f;
const int MAXN = 100010;

int v[MAXN];
int n, l, r;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	cin >> n >> l >> r;	
	for(int i=0; i<n; i++)
		cin >> v[i];

	sort(v, v+n);
	
	//Melhor resposta pode ser um valor entre dois consecutivos ou L ou R
	int ans = 0;	
	for(int i=1; i<n; i++){
		int m = (v[i-1]+v[i])/2;
		if(m >= l and m <= r)			
			ans = max( ans, min(v[i]-m, m - v[i-1]) );		
	}
	
	int mnl=INF;
	for(int i=0; i<n; i++)
		mnl = min(mnl, abs(v[i]-l));

	int mnr=INF;
	for(int i=0; i<n; i++)
		mnr = min(mnr, abs(v[i]-r));

	ans = max(ans, mnr);		
	ans = max(ans, mnl);		

	cout << ans << endl;
	
	return 0;
}
