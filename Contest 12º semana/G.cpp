#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int MAXN = 110;

int cont[MAXN];

int n, m;


int main() {
	int teste = 1;
	while(cin >> n >> m, n or m){		
		for(int i=1; i<=n; i++)
			cont[i] = 0;
			
		for(int i=0; i<m; i++){
			int a, b;
			cin >> a >> b;
			cont[a]++;
			cont[b]++;
		}
		int maior = 0;
		
		for(int i=1; i<=n; i++)
			maior = max(maior, cont[i]);
		
		cout << "Teste " << teste << endl;
		bool espaco = false;
		for(int i=1; i<=n; i++){
			if(cont[i] == maior){
				if(espaco)
					cout << " ";
				cout << i;
				espaco = true;
			}
		}
		cout << endl;
		cout << endl;
		
		teste++;
	}
	return 0;
}
