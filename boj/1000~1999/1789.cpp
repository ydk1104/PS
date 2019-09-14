#include<stdio.h>

int main(void){
	long long N;
	scanf("%lld", &N);
	long long sum=0;
	for(int i=1; i<=N+1; i++){
		sum+=i;
		if(sum>N){
			printf("%d", i-1);
			break;
		}
	}
}
