#include<stdio.h>

int a[101][101], b[101][101], c[101][101];

int main(void){
	int N, M, L, K;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%d", &a[i][j]);
		}
	}
	scanf("%d %d", &L, &K);
	for(int i=0; i<L; i++){
		for(int j=0; j<K; j++){
			scanf("%d", &b[i][j]);
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<K; j++){
			for(int k=0; k<M; k++){
				c[i][j] += a[i][k] * b[k][j];
			}
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
}
