#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef long double  ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

struct point2d {
    ll x, y;
    point2d() {}
    point2d(ll _x, ll _y){
		x = _x;
		y = _y;
	}
};

//Produto Vetorial
ll cross(point2d a, point2d b) {
    return a.x * b.y - a.y * b.x;
}

//Vetor a partir de dois pontos
point2d vetor(point2d a, point2d b){	
	return point2d(b.x-a.x, b.y-a.y);
}

using namespace std;
	
point2d v[300010];
	
bool cmp(point2d a, point2d b){
	return a.x < b.x;
}
	
int main(){
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> v[i].x >> v[i].y;
	}
	
	sort(v, v+n, cmp);
	
	vector<point2d> vp; 

	//Primeiro Pulo
	vp.push_back(v[0]);
	vp.push_back(v[1]);

	for(int i=2; i<n; i++){
		int sz = vp.size();
		point2d v_A_B = vetor(vp[sz-2], vp[sz-1]);
		point2d v_A_C = vetor(vp[sz-1], v[i]);
		
		//Enquanto for vantajoso trocar o último pulo por um novo
		while( cross(v_A_B, v_A_C) >= 0 ){
			vp.pop_back();			
			sz = vp.size();
			if(sz == 1)
				break;

			v_A_B = vetor(vp[sz-2], vp[sz-1]);
			v_A_C = vetor(vp[sz-1], v[i]);			
		}
		
		vp.push_back(v[i]);
	}	
	
	cout << vp.size()-1 << endl;
	
	return 0;
}   
