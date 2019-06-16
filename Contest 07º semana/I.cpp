#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--){
		int m, n;
		cin >> m >> n;
		
		map<string, string> dicionario;
		
		cin.ignore();

		for(int i=0; i<m; i++){
			string chave, texto;
			getline(cin, chave);
			getline(cin, texto);
			
			dicionario[chave] = texto;
		}
		
		for(int i=0; i<n; i++){
			string texto, line;
			getline(cin, texto);

			stringstream ss;
			ss << texto;
			
			bool primeira = true;
			
			while(ss >> line){
				if(!primeira)
					cout << " ";
				
				if(dicionario.count(line))
					cout << dicionario[line];
				else
					cout << line;
					
				primeira = false;
			}
			
			cout << endl;
		}
		
		cout << endl;		
	}

	return 0;
}
