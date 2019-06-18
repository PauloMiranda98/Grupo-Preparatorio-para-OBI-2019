#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef long double  ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

struct point2d {
    int x, y;
    point2d() {}
    point2d(int _x, int _y){
		x = _x;
		y = _y;
	}
};

//Produto Escalar
int dot(point2d a, point2d b) {
    return a.x * b.x + a.y * b.y;
}

//Norma do vetor
int norm(point2d a) {
    return dot(a, a);
}

//Produto Vetorial
int cross(point2d a, point2d b) {
    return a.x * b.y - a.y * b.x;
}

//Vetor a partir de dois pontos
point2d vetor(point2d a, point2d b){	
	return point2d(b.x-a.x, b.y-a.y);
}

int sinal(int x){
	if(x > 0)
		return 1;
	if(x < 0)
		return -1;
	return 0;
}

using namespace std;
	
point2d v[10];
	
int main(){
	
	for(int i=1; i<=7; i++)
		cin >> v[i].x >> v[i].y;
		
	//Vetores necessários para resolver o problema
	//Perceba que em nenhum momento foi necessário utilizar ponto flutuante

	point2d v_1_2 = vetor(v[1], v[2]);
	point2d v_1_3 = vetor(v[1], v[3]);

	point2d v_2_1 = vetor(v[2], v[1]);
	point2d v_2_3 = vetor(v[2], v[3]);
	point2d v_2_4 = vetor(v[2], v[4]);
	point2d v_2_5 = vetor(v[2], v[5]);
	point2d v_2_6 = vetor(v[2], v[6]);

	point2d v_4_5 = vetor(v[4], v[5]);
	point2d v_4_6 = vetor(v[4], v[6]);

	point2d v_5_7 = vetor(v[5], v[7]);
	
	//O ângulo ∠P2P1P3 é agudo (vértice em P1);
	if( dot(v_1_2, v_1_3) <= 0){
		cout << "N\n";
		return 0; 
	}
	
	//Os segmentos P1P2 e P1P3 tê o mesmo comprimento;	
	if( norm(v_1_2) != norm(v_1_3) ){
		cout << "N\n";
		return 0; 
	}
	
	//Os pontos P2, P3, P4 e P5 são colineares;
	if( ( cross(v_2_3, v_2_4) != 0) or ( cross(v_2_3, v_2_5) != 0) ){
		cout << "N\n";
		return 0; 
	}
		
	//Os pontos médios dos segmentos P2P3 e P4P5 são coincidentes;
	if( ((v[2].x + v[3].x) != (v[4].x + v[5].x)) or ((v[2].y + v[3].y) != (v[4].y + v[5].y)) ){
		cout << "N\n";
		return 0; 
	}

	//O segmento P2P3 tem comprimento maior que o segmento P4P5;
	if( norm(v_2_3) <= norm(v_4_5) ){
		cout << "N\n";
		return 0; 
	}

	//Os segmentos P4P6 e P5P7 são perpendiculares ao segmento P2P3;
	if( (dot(v_2_3, v_4_6) != 0) or (dot(v_2_3, v_5_7) != 0) ){
		cout << "N\n";
		return 0; 
	}

	//Os segmentos P4P6 e P5P7 têm o mesmo comprimento
	if( norm(v_4_6) != norm(v_5_7) ){
		cout << "N\n";
		return 0; 
	}

	//O segmento P1P6 deve interceptar a reta que contém o segmento P2P3 em um único ponto.
	if( sinal(cross(v_2_3, v_2_1)) == sinal(cross(v_2_3, v_2_6)) ){
		cout << "N\n";
		return 0; 
	}
		
	cout << "S\n";

	return 0;
}   
