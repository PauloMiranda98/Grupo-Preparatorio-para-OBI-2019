#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

long long n, a, b;

struct Par{
	int x;
	int y;
	
	Par(){
		
	}
	
	Par(int a, int b){
		x = a;
		y = b;
	}
	
};

//Módulo do Produto Vetorial
int cross(Par a, Par b) {
    return a.x * b.y - a.y * b.x;
}

Par vetor[110];
int memo[110][110];

bool compara(Par a, Par b){
	return a.y > b.y;
}

int pd(int ant, int atual){
	
	if(atual > n)
		return 0;
		
	if(memo[ant][atual] != -1)
		return memo[ant][atual];
	
	if(ant == 0)//Ninguem foi escolhido ainda
		return memo[ant][atual] = max(pd(atual, atual+1) + 1, pd(ant, atual+1) );		

	//Vetor do ponto A para o anterior
	Par v_a_ant(vetor[ant].x - a, vetor[ant].y - 0);
	//Vetor do ponto B para o anterior
	Par v_b_ant(vetor[ant].x - b, vetor[ant].y - 0);
	
	//Vetor do ponto A para o atual
	Par v_a_atual(vetor[atual].x - a, vetor[atual].y - 0);
	//Vetor do ponto B para o atual
	Par v_b_atual(vetor[atual].x - b, vetor[atual].y - 0);
	
 	if( (cross(v_a_atual, v_a_ant) > 0)  and (cross(v_b_atual, v_b_ant) < 0) ) //O atual pode ser escolhido
		return memo[ant][atual] = max(pd(atual, atual+1) + 1, pd(ant, atual+1) );
	else //O atual não pode ser escolhido
		return memo[ant][atual] = pd(ant, atual+1);
}

int main(){
	
	memset(memo, -1, sizeof(memo));
	
	cin >> n >> a >> b;
	
	for(int i = 1; i <= n; i++){
		cin >> vetor[i].x;
		cin >> vetor[i].y;				
	}
	
	//v[0] é inválido, significa que não foi escolhido
	
	sort(vetor+1, vetor + n + 1, compara);
	
	cout << pd(0, 1) << endl;
	
	return 0;
}
