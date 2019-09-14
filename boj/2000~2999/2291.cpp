#include<stdio.h>
#define ll long long

ll dp[11][221][221];
ll N, M, K;

void test_print(){
	int sum=0;
	for(int i=1; i<=M; i++) printf("%d\n", dp[N][i][M]), sum+=dp[N][i][M];
	printf("%d\n", sum);
}

int main(void){
	scanf("%lld %lld %lld", &N, &M, &K);
	dp[0][M][0] = 1;
	for(int i=0; i<N; i++){
		for(int j=1; j<=M; j++){
			for(int k=M; k>=j; k--){
				for(int m=j; m<=M; m++){
					dp[i+1][j][m] += dp[i][k][m-j];
				}
			}
		}
	}
	int k=0;
//	test_print();
	while(N>0){
		ll temp = 0;
		while(temp+dp[N][k][M] < K) temp+=dp[N][k][M], k++;
//		k--;
		K-=temp;
		printf("%d ", k);
		M-=k;
		N--;
	}
}
