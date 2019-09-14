#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	while(N--){
		long long int a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		long long int ans = 0;
		if(b*2>c){
			long long int temp = a/2;
			ans += temp*c;
			a %= 2;
		}
		ans += a*b;
		printf("%lld\n", ans);
	}
}
