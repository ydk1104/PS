#include<stdio.h>

int C[100000][200];

int nCr(int N, int K){
	if(K==0) return 1;
	if(K==1) return N;
	if(K==N) return 1;
	if(K==N-1) return N;
	if(C[N][K] != 0) return C[N][K];
	C[N][K] = nCr(N-1, K-1) + nCr(N-1, K);
	return C[N][K];
}

int main(void){
	int N, K;
	scanf("%d %d", &N, &K);
	while(N>0 || K>0){
		if(K*2>N) K = N-K;
		printf("%d\n", nCr(N, K));
		scanf("%d %d", &N, &K);
	}
	return 0;
}
