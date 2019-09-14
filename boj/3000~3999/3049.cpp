#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	printf("%d", N*(N-1)*(N-2)*(N-3)/24);
}
