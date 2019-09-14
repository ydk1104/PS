#include<stdio.h>

int main(void){
	long long int N;
	scanf("%lld", &N);
	long long int ans = 0;
	for(int i=1; i<N; i++){
		ans += (N+1)*i;
	}
	printf("%lld", ans);
}
