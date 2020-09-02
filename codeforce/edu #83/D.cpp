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

// 1. �ϳ��� pair�� �־����
// 2. �� pair�� ���� ū �����ϼ�����
// 3. ���� ū ���� �ϳ�, pair�� �̷�� �ΰ��� ���� �ϳ��� �̾ƾ���(-3, -2)
// 4. ��ġ�ϴ� ����� pair�� ���ʿ� �ϳ�, �����ʿ� �ϳ�, �߾ӿ� ���� ū ���ڰ� ����
// 5. �̸� ���� 4��° ������ �׻� ������. 
// 6. ����� �� : 2���� ���ڸ� ����(MC2) ���� ū���� ���� ū����??
// 6-2. ������ MCN-3���Ǽ��ڸ� �̾ƾ���. �̰� ���???

// 6-B. MCN-1���� ���ڸ� ����. ���� ū���� ���� ū����. pair�� ���, N-2���� ������̴� ������. 
 
// 7. �迭�ϴ� �������� 3���� ��ġ�� �����̹Ƿ�, (N-3)C 0 to (N-3), ���� 2^N-3�ε���. ���� or �߾� or ����ϱ�,
// ���ʿ� � �������� ������ ��. 
