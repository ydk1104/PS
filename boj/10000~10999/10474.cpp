#include<stdio.h>

int main(void){
	int N, M;
	while(scanf("%d %d", &N, &M),N|M){
		printf("%d %d / %d\n", N/M, N%M, M);
	}
}
