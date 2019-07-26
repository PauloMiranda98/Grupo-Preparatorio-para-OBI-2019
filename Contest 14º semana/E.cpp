#include <bits/stdc++.h>

using namespace std;

//Para resolver esse problema precisa aprender a técnica de Sweep-line

struct Evento{
	int x, y1, y2;
	bool entrada;
	Evento(){}
	Evento(int _x, int _y1, int _y2, bool b){
		x = _x;
		y1 = _y1;
		y2 = _y2;
		entrada = b;		
	}
};

Evento eventos[200010];

bool cmp(Evento a, Evento b){
	return a.x < b.x;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2; 
		swap(y1, y2);
		eventos[i] = Evento(x1, y1, y2, true);
		eventos[n+i] = Evento(x2, y1, y2, false);
	}

	//Ordenando pelo x
	sort(eventos, eventos + 2*n, cmp);
	set<int> status;
	int ans = 0;
	
	//Sweep-line
	for(int i=0; i<2*n; i++){
		int y1 = eventos[i].y1;
		int y2 = eventos[i].y2;

		if(eventos[i].entrada){//Entrada
			//Limpando o intervalo fechado [y1, y2]
			auto lo = status.lower_bound(y1);
			auto hi = status.upper_bound(y2);
			status.erase(lo, hi);				
			
			//inserindo um intervalo
			status.insert(y1);
			status.insert(y2);			
		}else{//Saída
			auto lo = status.upper_bound(y1);
			auto hi = status.lower_bound(y2);

			//Se o intervalo aberto (y1, y2) é vazio então é o retangulo mais interno e precisa de um WIFI
			if(lo == hi){
				ans++;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
