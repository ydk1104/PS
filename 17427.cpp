#include<stdio.h>

int main(void){
	long long N, ans=0;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		ans += N/i*i;
	}
	printf("%lld", ans);
}
