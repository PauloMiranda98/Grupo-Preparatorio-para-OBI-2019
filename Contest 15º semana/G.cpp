#include <bits/stdc++.h>

using namespace std;


int main(){	
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int n, substituido=0, consertado=0;
	cin >> n;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		if(x<50)
			substituido++;
		else if(x<85)
			consertado++;			
	}

	cout << substituido << " " << consertado << endl;
	
	return 0;
}
