#include <iostream>
#include <algorithm>

using namespace std;

struct Caixa{
	int p;
	int r;	
};

bool compara(Caixa a, Caixa b){
	return a.r < b.r;
}

Caixa vetor[1010];
int pd[1010];

int main(){
	int n;
	
	scanf("%d", &n);
	
	for(int i=0; i < n; i++){
		cin >> vetor[i].p;
		cin >> vetor[i].r;		
	}
	
	sort(vetor, vetor + n, compara);
	
	for(int i=0; i<=n; i++){
		pd[i] = 0x3f3f3f3f;
	}
	
	//pd[i] = o menor peso com i caixas
	
	pd[0] = 0;
	int maximo = 0;
	
	for(int i=0; i<n; i++){
		for(int q=n; q>=0; q--){
			if( (pd[q]+vetor[i].p) <= vetor[i].r){ // eh possivel colocar a caixa em baixo
				if( (pd[q]+vetor[i].p) < pd[q+1] ){ // Verificar se eh vantajoso atualizar a nova forma de formar o q+1
					pd[q+1] = pd[q]+vetor[i].p;
					maximo = max(maximo, q+1);
				}
			}
		}
	}
		
	printf("%d\n", maximo);
		
	return 0;
}
