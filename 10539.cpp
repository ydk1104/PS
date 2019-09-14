#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	long long prev=0;
	for(int i=1; i<=N; i++){
		long long x;
		scanf("%d", &x);
		printf("%lld ",x*i-prev);
		prev=x*i;
	}
}
