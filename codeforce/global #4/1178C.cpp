#include<stdio.h>

int main(void){
	long long int N, M;
	scanf("%lld %lld", &N, &M);
	N=N+M-2;
	long long int ans=4;
	for(int i=0; i<N; i++){
		ans = ans << 1;
		ans %= 998244353;
	}
	printf("%d",ans);
}
