#include<stdio.h>

long long gcd(long long x, long long y){
	return y?gcd(y,x%y):x;
}

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		long long r,b,k;
		scanf("%lld %lld %lld", &r, &b, &k);
		int ans = 1;
		if(r>b){
			long long temp = r; r = b; b = temp;
		}
		long long g = gcd(r,b); r /= g; b /= g;
		if((b-2)/r+1 >= k) ans = 0;
		printf("%s\n", ans ? "OBEY" : "REBEL");
	}	
}
