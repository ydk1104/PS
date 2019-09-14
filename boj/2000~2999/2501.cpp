#include<stdio.h>

int main(void){
	int N, K;
	scanf("%d %d", &N, &K);
	for(int i=1; i<=N; i++){
		if(N%i==0) K--;
		if(!K){
			printf("%d", i);
			return 0;
		}
	}
	printf("0");
}
