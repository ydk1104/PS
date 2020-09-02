#include<stdio.h>

const int mod = 998244353;
long long dp[1400][50];

long long nCr(int x, int y){
	if(dp[x][y]) return dp[x][y];
	if(y==0 || x==y) return 1;
	if(y>x){
		printf("Error");
	}
	return dp[x][y] = (nCr(x-1, y-1) + nCr(x-1, y)) % mod;
}

long long pow(long long x, long long y){
	long long temp = 1;
	while(y){
		if(y%2){
			temp *= x;
			temp %= mod;
		}
		x *= x;
		x %= mod;
		y /= 2;
	}
	return temp;
}

long long dp2[200010];

long long nCr2(int x, int y){
	dp2[1] = 1;
	for(int i=2; i<=x; i++){
		dp2[i] = dp2[i-1] * i;
		dp2[i] %= mod;
	}
	
	long long temp = dp2[x];
	temp *= pow(dp2[y], mod-2);
	temp %= mod;
	temp *= pow(dp2[x-y], mod-2);
	temp %= mod;
	return temp;
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	if(N==2){
		printf("0");
		return 0;
	}
	long long ans = 0;
	
	ans = nCr2(M, N-1);
	ans *= (N-2);
	ans %= mod; 
	
	long long temp = 1;
	for(int i=0; i<N-3; i++){
		temp *= 2;
		temp %= mod;
	}
	ans *= temp;
	ans %= mod;
	printf("%lld", ans);
}

// 1. 하나의 pair가 있어야함
// 2. 이 pair은 가장 큰 숫자일순없음
// 3. 가장 큰 숫자 하나, pair을 이루는 두개의 숫자 하나를 뽑아야함(-3, -2)
// 4. 배치하는 방법은 pair은 왼쪽에 하나, 오른쪽에 하나, 중앙에 가장 큰 숫자가 고정
// 5. 이를 통해 4번째 조건이 항상 만족됨. 
// 6. 경우의 수 : 2개의 숫자를 뽑음(MC2) 이중 큰값이 가장 큰숫자??
// 6-2. 나머지 MCN-3개의숫자를 뽑아야함. 이건 어떻게???

// 6-B. MCN-1개의 숫자를 뽑음. 가장 큰값은 가장 큰숫자. pair의 경우, N-2개중 어느것이던 가능함. 
 
// 7. 배열하는 가짓수는 3개의 위치는 고정이므로, (N-3)C 0 to (N-3), 따라서 2^N-3인듯함. 왼쪽 or 중앙 or 가운데니까,
// 왼쪽에 몇개 들어가는지만 뽑으면 됨. 
