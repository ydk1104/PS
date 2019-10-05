#include<stdio.h>

long long pow(int a, int b){
	long long mod = 16769023;
	long long temp = a, ans = 1;;
	while(b){
//		printf("%d %d\n", b, ans);
		if(b%2) ans *= temp;
		if(ans>mod) ans %= mod;
		temp *= temp;
		if(temp>mod) temp %= mod;
		b/=2;
	}
	return ans;
}

int main(void){
	int N;
	scanf("%d", &N);
	N = (N+1)/2;
	printf("%lld", pow(2, N));
}
