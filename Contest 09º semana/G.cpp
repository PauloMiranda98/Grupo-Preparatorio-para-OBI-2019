#include <bits/stdc++.h>

using namespace std;

struct Horario{
	int t;
	int d;	
};

Horario v[10010];
bool comp(Horario a, Horario b){
	return a.d < b.d;
}

int main() {
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++)
		cin >> v[i].t >> v[i].d;
		
	sort(v, v+n, comp);
	
	int tempo = 0;
	int res = 0;	
	
	for(int i=0; i<n; i++){
		tempo += v[i].t;
		res = max(res, tempo - v[i].d);
	}
	
	cout << res << endl;
	
	return 0;
}
