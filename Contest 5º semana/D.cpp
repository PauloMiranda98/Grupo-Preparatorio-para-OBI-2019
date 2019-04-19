#include <iostream> 

using namespace std;

int vetor[30];

int main(){

	int b, n;
	cin >> b >> n;

	while(b || n){
		for(int i=1; i<=b; i++)
			cin >> vetor[i];	
		
		while(n--){
			int x, y, z;
			cin >> x >> y >> z;
			
			vetor[x] -= z;
			vetor[y] += z;		
		}
	
		bool r = false;
			
		for(int i=1; i<=b; i++){
			if(vetor[i] < 0){
				r = true;
				break;
			}
		}
	
		if(r)
			cout << "N" << endl;
		else	
			cout << "S" << endl;
		
		cin >> b >> n;
	}
	return 0;  
}
