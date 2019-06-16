#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	set<int> setA, setB;
	vector<int> v;
	
	cin >> n >> m;
	
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		setA.insert(x);
		v.push_back(x);
	}

	for(int i=0; i<m; i++){
		int x;
		cin >> x;		
		setB.insert(x);
		v.push_back(x);
	}

	for(int x: v){
		if(setA.count(x) and setB.count(x)){
			setA.erase(x);
			setB.erase(x);
		}
	}

	cout << min(setA.size(), setB.size()) << endl;

	return 0;
}
