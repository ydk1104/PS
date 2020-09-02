#include<stdio.h>

int a[101][101];
int sum[101];

int main(void){
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			sum[j] += a[j][i];
			if(sum[j] >= K){
				printf("%d %d", j+1, i+1);
				return 0;
			}
		}
	}
}
