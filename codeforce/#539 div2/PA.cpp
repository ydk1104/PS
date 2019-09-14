#include<stdio.h>

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	if(N<=M+1){
		printf("%d", N-1);
	}
	else{
		int sum = 0;
		for(int i=1; M+i<N; i++){
			sum += i;
		}
		printf("%d", N-1 + sum);
	}
}
