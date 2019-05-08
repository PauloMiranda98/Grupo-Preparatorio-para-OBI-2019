#include <iostream>
#include <vector>

using namespace std;

vector<int> primos;

void crivo(int n){
	//inicialmente, todo numero > 2 'é primo'
	vector<bool> eh_primo(n+1, true);

	eh_primo[0] = false;
	eh_primo[1] = false;

	for(int i=2; i<=n; i++){
		if(eh_primo[i]){
			primos.push_back(i);
			for(int j= i+i; j<=n; j+=i)
				eh_primo[j] = false;			
		}
	}	
}

int main() {	

	int n;
	cin >> n;
	crivo(n);
	
	for(int p : primos)
		cout << p << " ";
	
	cout << "\n";
	
	return 0;
}
