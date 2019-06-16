#include <bits/stdc++.h>

using namespace std;


int main() {	
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int n;
	set<int> st;

	cin >> n;
	
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		st.insert(x);
	}
	
	cout << st.size() << endl;
	
	return 0;
}
