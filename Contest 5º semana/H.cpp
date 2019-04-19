#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;


//qtd (ultimo número escolhido até então, quantidade que falta escolher, quanto falta para completar a soma)

ll qtd(int ultimo, int k, int falta){
	if( k == 0){
		if(falta == 0)
			return 1LL;
		else
			return 0LL;			
	}
	
	ll ans = 0;
	
	for(int i=ultimo+1; i<=falta; i++)
		ans += qtd(i, k-1, falta - i);

	return ans;
}

int main() {
	int r, k;
	
	cin >> r >> k;
	
	cout << qtd(0, k, r) << "\n";

	return 0;
}
