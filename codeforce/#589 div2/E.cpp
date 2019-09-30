#include<stdio.h>

long long mod = 1e9+7;

long long pow(long long x, long long y){ // x^y
	if(y<=0) return 1;
	if(x<0) x+=mod;
	long long temp = x, ans = 1;
	while(y){
		if(y%2){
			ans *= temp;
			ans %= mod;
		}
		temp *= temp;
		temp %= mod;
		y /= 2;
	}
	return ans%mod;
}

long long dp[251][251];
long long dp2[251][251][251];

long long nCr(int x, int y){
	if(y<0 || y>x) return 0;
	if(y==0 || y==x) return 1;
	if(dp[x][y]) return dp[x][y];
	return dp[x][y] = (nCr(x-1,y-1) + nCr(x-1,y)) % mod;
}

long long cnt;

long long f(long long a, long long b, long long c, long long y){
//	if(a==1 && b==1) return 1;
	if(c<0) return 0;
	if(dp2[a][b][c]) return dp2[a][b][c];
	if(!c) return dp2[a][b][c] = pow(pow(y,b)-pow(y-1,b),a);
	if(a==1) return dp2[a][b][c] = pow(y,b-c);
	long long ans = 0;
	for(int i=1; i<=b; i++){
		long long temp = 0;
		for(int j=i; j>=0; --j){
			long long temp2 = f(a-1, b, c-(i-j), y);
			if(!temp2) break;
			temp2 *= nCr(c, (i-j); temp2 %= mod;
			temp2 *= nCr(b-c, j); temp2 %= mod;
			temp += temp2; if(temp>mod) temp -= mod;
		}
		temp *= pow(y-1, b-i); temp %= mod;
		ans += temp; if(ans>mod) ans-=mod;
//		printf("when %d %d %d, ans : %lld\n", a,b,c, ans);
	}
//	printf("when %d %d %d, ans : %d\n", a,b,c,ans);
	return dp2[a][b][c] = ans;
}

int main(void){
	long long x,y;
	scanf("%lld %lld", &x, &y);
	printf("%lld", f(x,x,x,y));
}
