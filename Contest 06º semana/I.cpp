#include <iostream>
#include <vector>

using namespace std;

int pos_primo[1300010];

void crivo(int n){
	//inicialmente, todo numero > 2 'é primo'
	int pos = 1;
	vector<bool> eh_primo(n+1, true);

	eh_primo[0] = false;
	eh_primo[1] = false;

	for(int i=2; i<=n; i++){
		if(eh_primo[i]){
			pos_primo[i] = pos;
			pos++;
			
			for(int j= i+i; j<=n; j+=i)
				eh_primo[j] = false;			
		}
	}	
}

int main() {	
	crivo(1300000);

	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		
		cout << pos_primo[x] << "\n";
	}
	
	return 0;
}
