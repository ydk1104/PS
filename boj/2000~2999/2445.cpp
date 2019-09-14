#include<stdio.h>

int N;

void print(int i){
	for(int j=1; j<=i; j++){
		printf("*");
	}
	for(int j=1; j<=2*N-2*i; j++){
		printf(" ");
	}
	for(int j=1; j<=i; j++){
		printf("*");
	}
	printf("\n");	
}

int main(void){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		print(i);
	}
	for(int i=N-1; i>=1; i--){
		print(i);
	}
}
