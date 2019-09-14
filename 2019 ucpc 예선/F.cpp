#include<stdio.h>
#include<algorithm>

int cnt[1001][344];
double dp[1001];

double f(int x, int y, int z){
	if(x==y && y==z) return 10000+1000*x;
	if(x==y) return 1000+100*x;
	if(y==z) return 1000+100*y;
	if(z==x) return 1000+100*z;
	if(x>y && x>z) return 100*x;
	if(y>z) return 100*y;
	return 100*z;
}

int main(void){
	int N;
	scanf("%d", &N);
	double ans = 0;
	for(int i=0; i<=N-1; i++){
		double sum=0, sum2=0;
		for(int j=0; j<216; j++){
			int t=j, x,y,z;
			x=t/36;
			t%=36;
			y=t/6;
			z=t%6;
			double now = f(x+1, y+1, z+1);
			if(now>=)
			sum += std::max(dp[i-3], now);
		}
		printf("%lf %lf\n", sum, dp[i]=sum/216);
	}
	printf("%lf", dp[N-2]);
}
// 3 : 1229.166666666667
// 4 : 1663.194444
