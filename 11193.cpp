#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	long long ans = 1;
	for(int i=1; i<=N; i++){
		ans *= i;
		while(ans%10==0) ans/=10;
		ans %= (long long)1e14;
//		printf("%d : %03d\n", i, ans%1000);
	}
	if(N>6)printf("%03d", ans%1000);
	else printf("%d", ans);
}
