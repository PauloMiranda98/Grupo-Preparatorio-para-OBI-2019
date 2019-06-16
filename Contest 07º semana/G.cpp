#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int n, c;
	
	cin >> c >> n;
	
	map<int, int> mapa;
	map<int, int> res;
		
	for(int i=0; i<c; i++){
		int id, versao;
		cin >> id >> versao;
		
		mapa[id] = versao;
	}

	for(int i=0; i<n; i++){
		int id, versao;
		cin >> id >> versao;
		
		if(versao > mapa[id])
			res[id] = max(res[id], versao);
	}
	
	for(auto p: res){
		cout << p.first << " " << p.second << '\n';
	}

	return 0;
}
