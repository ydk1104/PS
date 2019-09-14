#include<stdio.h>

int factorial(int N){
	if(N==0) return 1;
	if(N==1) return N;
	return N * factorial(N-1);
}

int main(void){
	int N;
	scanf("%d", &N);
	printf("%d", factorial(N));
}
