#include <bits/stdc++.h>

using namespace std;

map<int, pair<char, int> > mapa;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int n;
	cin >> n;

	for(int i=0; i < n; i++){
		int e, d;
		char c;
		cin >> e >> c >> d;
		
		mapa[e] = make_pair(c, d);
	}
	
	int e = 0;
	string res;
	
	while(e != 1){
		res += mapa[e].first;
		e = mapa[e].second;
	}
	
	cout << res << endl;
	
	return 0;
}
