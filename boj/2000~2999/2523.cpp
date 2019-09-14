#include<stdio.h>

void printstar(int x){
	for(int i=1; i<=x; i++) printf("*");
	printf("\n");
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		printstar(i);
	}
	for(int i=N-1; i>=1; i--){
		printstar(i);
	}
}
