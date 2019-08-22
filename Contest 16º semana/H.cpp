#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;

// Counting Inversions: O(N*log(N))
ll ci(vector<int> &v){
	
	ll inv = 0LL;
	
	if(v.size() == 1) return 0;
	
	vector<int> u1, u2;
	
	for(int i=0; i < int(v.size()/2); i++){
		u1.push_back(v[i]);
	}
	
	for(int i=v.size()/2; i < int(v.size()); i++){
	 	u2.push_back(v[i]);
	}
	
	inv += ci(u1);
	inv += ci(u2);
	
	u1.push_back(INF);
	u2.push_back(INF);
	
	int ini1=0, ini2=0;
	
	for(int i=0; i < int(v.size()); i++){
		
		if(u1[ini1] <= u2[ini2]){			
			v[i] = u1[ini1];			
			ini1++;
		}else{			
			v[i] = u2[ini2];
			ini2++;
						
			inv += ll(u1.size() - ini1) - 1LL;
		}
	}
	
	return inv;
}

vector<int> v;
int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x, y;
	ll hr, vt;
	cin >> x >> y;
	cin >> hr >> vt;
	
	vector<pii> v_hr(hr);
	vector<pii> v_vt(vt);
	
	for(int i=0; i<hr; i++)
		cin >> v_hr[i].F >> v_hr[i].S;
	sort(v_hr.begin(), v_hr.end());
	
	for(int i=0; i<vt; i++)
		cin >> v_vt[i].F >> v_vt[i].S;
	sort(v_vt.begin(), v_vt.end());
		
	ll ans = (hr+1LL)*(vt+1LL);
	
	//Contar inversoes horizontais
	v.resize(hr);
	for(int i=0; i<hr; i++)
		v[i] = v_hr[i].S;	
	ans += ci(v);
	
	//Contar inversoes verticais
	v.resize(vt);
	for(int i=0; i<vt; i++)
		v[i] = v_vt[i].S;	
	ans += ci(v);
	
	cout << ans << endl;

	return 0;
	

}
