#include<stdio.h>

void star(int N){
	if(N==3){
		printf("  *  ");
		printf("\n * * ");
		printf("\n*****");
	}
}

int main(void){
	int N;
	scanf("%d", &N);
	star(N);
}
