#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N-i; j++){
			printf(" ");
		}
		for(int j=1; j<=i*2-1; j++){
			printf("*");
		}
		printf("\n");
	}
}
