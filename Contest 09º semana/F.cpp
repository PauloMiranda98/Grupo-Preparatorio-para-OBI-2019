#include <bits/stdc++.h>

using namespace std;

struct Horario{
	int inicio;
	int fim;	
};

Horario v[10010];
bool comp(Horario a, Horario b){
	return a.fim < b.fim;
}

int main() {
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++)
		cin >> v[i].inicio >> v[i].fim;
		
	sort(v, v+n, comp);
	int ultimo = 0;
	int res = 0;	
	
	for(int i=0; i<n; i++){
		if(v[i].inicio >= ultimo){
			ultimo = v[i].fim;
			res++;
		}	
	}
	
	cout << res << endl;
	
	return 0;
}
