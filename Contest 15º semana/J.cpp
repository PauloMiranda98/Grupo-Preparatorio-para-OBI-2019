#include <bits/stdc++.h>

using namespace std;

set<string> pre, suf;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int n;
	
	cin >> n;
	
	for(int k=0; k<n; k++){
		string s;
		cin >> s;
		
		//Verificar se já não existe uma string s
		if(pre.count(s) or suf.count(s)){
			cout << s << endl;
			return 0;
		}
		for(int i=1; i<10; i++){
			//Verificar se a string s pode ser formada por um sufixo de alguem concatenado com um prefixo de alguém.
			if( suf.count(s.substr(0, i)) and pre.count(s.substr(i)) ){
				cout << s << endl;
				return 0;
			}
		}
		
		//Inserir o prefixo e o sufixo da nova string
		for(int i=1; i<10; i++){
			pre.insert(s.substr(0, i));
			suf.insert(s.substr(10-i));
		}
		
		//Inserir a nova string
		pre.insert(s);
		suf.insert(s);		
	}
	
	cout << "ok" << endl;

	return 0;
}
