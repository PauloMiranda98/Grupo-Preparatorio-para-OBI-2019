#include <iostream>

using namespace std;

typedef long long int ll;

ll mdc(ll a, ll b){
	if(b == 0)
		return a;
	return mdc(b, a%b);
}

ll mmc(ll a, ll b){
	return (a/mdc(a,b))*b;
}

int main() {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	
	// a/b + c/d == (a*d + c*b)/b*d
	
	ll x = (a*d + c*b);
	ll y = b*d;
	ll mdc_x_y = mdc(x,y);
	
	cout << x/mdc_x_y << " " << y/mdc_x_y << "\n";
	
	return 0;
}

