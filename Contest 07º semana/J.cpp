#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int n, d;
	
	while(cin >> n >> d, (n or d)){
		string s;
		stack<char> pilha;
		cin >> s;
		
		for(char c: s){
			if(pilha.empty() or pilha.top() >= c)
				pilha.push(c);
			else{
				while( (d > 0) and !pilha.empty() and (pilha.top() < c) ){
					pilha.pop();
					d--;
				}
				
				pilha.push(c);
			}
		}
		
		while(d > 0){
			pilha.pop();
			d--;
		}
		
		string res;
		while(!pilha.empty()){
			res += pilha.top();
			pilha.pop();
		}		

		reverse(res.begin(), res.end());

		cout << res << '\n';	
	}
	
	return 0;
}
