#include<stdio.h>

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	long long ans = 1;
	int min = N/M;
	int max = min+1;
	for(int i=0; i<N%M; i++){
		ans *= max;
	}
	for(int i=0; i<M-N%M; i++){
		ans *= min;
	}
	printf("%lld", ans);
}
