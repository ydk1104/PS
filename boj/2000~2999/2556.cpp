#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		for(int j=0; j<N; j++){
			printf("*");
		}
		printf("\n");
	}
}
