#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

struct A{
	int pos;
	int val;
};

A v[MAXN];
bool mark[MAXN];
int n;

bool comp(A a, A b){
	return a.val > b.val;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> v[i].val;
		v[i].pos = i+1;
	}
	
	int ans = 0;
	int total = 0;
	sort(v, v+n, comp);

	int i = 0;
	while(i<n){
		int j=i;

		while(j<n and (v[i].val == v[j].val)){
			if( mark[v[j].pos-1] and mark[v[j].pos+1])
				total--;
			else if( !mark[v[j].pos-1] and !mark[v[j].pos+1])
				total++;

			mark[v[j].pos] = true;
			j++;
		}
		
		ans = max(total, ans);
		i = j;	
	}
	
	//ans + parte de baixo
	cout << ans+1 << "\n";
			
	return 0;
}
