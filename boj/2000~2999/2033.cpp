#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i*10<=N; i*=10){
		while(N%(i*10) >= i*5) N += i;
		N -= (N%(i*10));
	}
	printf("%d", N);
}
