#include <iostream>

using namespace std;
typedef long long int ll;

int main(){

    ll n;
    cin >> n;
    
    for(ll i=2LL; i*i<=n; i++){
		if(n%i == 0){
			cout << "S" << "\n";
			return 0;
		}
	}

	cout << "N" << "\n";

	return 0;
}
