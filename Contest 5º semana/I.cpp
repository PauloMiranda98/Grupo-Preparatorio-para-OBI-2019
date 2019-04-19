#include <iostream>

using namespace std;

int v[1010];

int main() {
	int n;
	
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> v[i];
	
	bool trocou = false;
	
	for(int i=0; i<(n-1); i++){
		if( (v[i] == 0) or ( (v[i] == 5) and (v[n-1] > v[i]) ) ){
			swap(v[i], v[n-1]);
			trocou = true;
			break;
		}
	}
	
	if(trocou == false){
		for(int i=n-2; i>=0; i--){
			if(v[i] == 5){
				swap(v[i], v[n-1]);
				trocou = true;
				break;
			}	
		}	
	}
	
	if(trocou){
		for(int i=0; i<n; i++){
			if(i > 0)
				cout << " ";
			cout << v[i];
		}
		cout << "\n";
	}else{
		cout << -1 << "\n";
	}
	
	return 0;
}
