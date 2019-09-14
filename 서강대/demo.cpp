#include<stdio.h>

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=1; i<=M; i++){
		for(int j=1; j<=N; j++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
