#include <iostream>

using namespace std;

int v[10010];
int main() {
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	
	for(int d=0; d<=8; d++){
		for(int i=0;i<n; i++){
			if(v[i] == d){
				// Todos os vizinho de i que forem igual a -1 vao receber d+1
							
				if( ((i-1)>=0) and (v[i-1] == -1) )
					v[i-1] = d+1;

				if( ((i+1)<n) and (v[i+1] == -1) )
					v[i+1] = d+1;				
			}
		}
	}
	
	for(int i=0; i<n; i++){
		//Se alguem ainda for -1 então na verdade ele é 9
		if(v[i] == -1)
			v[i] = 9;
		cout << v[i] << " ";
	}
	
	cout << "\n";
	
	return 0;
}

