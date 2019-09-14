#include<stdio.h>

int main(void){
	int a, b, N;
	scanf("%d %d %d", &a, &b, &N);
	printf("%d", (N-a)/(a-b)+1+!!((N-a)%(a-b)));
}
