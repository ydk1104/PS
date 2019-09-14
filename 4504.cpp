#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	int T;
	while(scanf("%d",&T),T){
		printf("%d is ", T);
		if(T%N) printf("NOT ");
		printf("a multiple of %d.\n", N);
	}
}
