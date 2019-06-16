#include <bits/stdc++.h>
#define F first 
#define S second 

using namespace std;

typedef pair<int, int> pii;

vector<pii> v;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int k, n;
	cin >> k >> n;
	
	v.resize(n);

	for(int i=0; i < n; i++){
		cin >> v[i].F >> v[i].S;
	}
	
	sort(v.begin(),  v.end());
	
	
	int i=0;

	while(i < n){
		int ini = v[i].F;
		int fim = v[i].S;
		i++;
		while( (i<n) and v[i].F <= fim){
			fim = max(fim, v[i].S);
			i++;
		}
		
		cout << ini << " " << fim << '\n';
		
	}
	
	return 0;
}
