#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>

using namespace std;

const int NSQRT = 800;
const int MAXN = 200010;
typedef long long ll;

ll vF[MAXN];
ll sqrtF[NSQRT];
ll sizeF[NSQRT];

ll vT[MAXN];
ll sqrtT[NSQRT];
ll sizeT[NSQRT];

int n, m;

inline
void updateF(int idx, int x){
	int p = idx/NSQRT + 1;
	
	for(int i=idx; i < p*NSQRT; i++){
		vF[i] += x;
		x--;
		if(x <= 0)
			return;
	}
	for(; p<NSQRT; p++){
		if(x >= NSQRT){			
			sqrtF[p] += x;
			sizeF[p]++;
			x-= NSQRT;
		}else{
			break;
		}
	}
	if(x <= 0)
		return;
		
	for(int i=p*NSQRT; i <= n; i++){
		vF[i] += x;
		x--;
		if(x <= 0)
			return;
	}
	
}

inline
void updateT(int idx, int x){
	int p = idx/NSQRT;
	
	for(int i=idx; i >= p*NSQRT; i--){
		vT[i] += x;
		x--;
		if(x <= 0)
			return;
	}
	p--;
	for(; p>=0; p--){
		if(x >= NSQRT){			
			sqrtT[p] += x;
			sizeT[p]++;
			x-= NSQRT;
		}else{
			break;
		}
	}
	if(x <= 0)
		return;
	for(int i=(p+1)*NSQRT - 1; i >= 0; i--){
		vT[i] += x;
		x--;
		if(x <= 0)
			return;
	}	
}

inline
ll queryF(int i){
	return vF[i] + (sqrtF[i/NSQRT] - ll(i%NSQRT)*sizeF[i/NSQRT]);
}

inline
ll queryT(int i){
	return vT[i] + (sqrtT[i/NSQRT] - ll(NSQRT -(i%NSQRT) - 1)*sizeT[i/NSQRT]);
}

inline
ll query(int i){
	return queryT(i) + queryF(i);
}

int main() {
	scanf("%d%d", &n, &m);
	
	for(int q=0; q<m; q++){
		int op;
		scanf("%d", &op);
		if(op == 1){
			int i, x;
			scanf("%d%d", &i, &x);
			updateF(i, x);
		}else if(op == 2){
			int i, x;
			scanf("%d%d", &i, &x);
			updateT(i, x);
		}else{
			int i;
			scanf("%d", &i);
			printf("%lld\n", query(i));			
		}
	}
	
	return 0;
}
