#include <iostream>

using namespace std;

int mdc(int a, int b){
	if(b == 0)
		return a;
	return mdc(b, a%b);
}

int main() {
	int n;
	int ans = 0; //0 é o elementro neutro no MDC
	cin >> n;
	
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		
		ans = mdc(ans, x);
	}
	
	cout << ans << "\n";
	
	return 0;
}

