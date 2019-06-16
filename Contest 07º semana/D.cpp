#include <bits/stdc++.h>

using namespace std;

typedef pair<string, int> psi;

psi v[10010]; 

set<string> times[1010]; 

bool comp(psi a, psi b){	
	return a.second > b.second;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int n, t;
	cin >> n >> t;
	
	for(int i=0; i<n; i++){
		cin >> v[i].first >> v[i].second;
	}
	
	sort(v, v + n, comp);
	
	for(int i=0; i<n; i++){
		times[i%t].insert(v[i].first);
	}

	for(int i=0; i<t; i++){
		cout << "Time " << (i+1) << endl;
		for(string s: times[i])
			cout << s << endl;
		cout << endl;
	}
	
	return 0;
}   
