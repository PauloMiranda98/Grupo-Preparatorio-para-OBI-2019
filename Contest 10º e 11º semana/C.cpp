#include <bits/stdc++.h>

using namespace std;

#define PB push_back 
#define MAXN 300100

//Longest Increasing Subsequence: O(N*log(N))
int lis(string &v){
	
	vector<char> pilha, resp;
	int pos[MAXN], pai[MAXN];
	
	for(int i=0; i < int(v.size()); i++){
		
		//vector<int>::iterator it = lower_bound(pilha.begin(), pilha.end(), v[i]); // Do not accept repeated values
		vector<char>::iterator it = upper_bound(pilha.begin(), pilha.end(), v[i]); //Accept repeated values
		
		int p = it-pilha.begin();
		
		if(it==pilha.end()) 
			pilha.PB(v[i]);
		else 
			*it = v[i];
		
		pos[p] = i;
		
		if(p==0) 
			pai[i] = -1; 			
		else 
			pai[i] = pos[p-1];
	}
	
	int p = pos[pilha.size() - 1];
	
	while(p >= 0){
		resp.PB(v[p]);
		p=pai[p];
	}
	
	reverse(resp.begin(), resp.end());
	
	return resp.size();
}

string s;
int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
		
	cout << lis(s) << endl;
					
	return 0;
	
}
