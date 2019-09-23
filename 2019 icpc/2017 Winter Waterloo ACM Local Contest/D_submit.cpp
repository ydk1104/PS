#include<stdio.h>

long long arr[31][901];

long long nCr[31][31];
long long mod = 1e9+7;
long long C(int n, int r){
	if(nCr[n][r]) return nCr[n][r];
	if(r==1 || r==n-1) return nCr[n][r] = n;
	if(r==0 || r==n) return nCr[n][r] = 1;
	return nCr[n][r] = (C(n-1, r-1) + C(n-1, r)) % mod;
}

int main(void){
	int N, K;
	scanf("%d %d", &N, &K);
	if(K > N*(N+1)/2){
		printf("0");
		return 0;
	}
	arr[1][1] = 1;
	for(int i=2; i<=N; i++){
		for(int j=0; j<=K; j++){
			for(int k=0; k<i; k++){
				if(k==0 || k==i-1){
					arr[i][j] += arr[i-1][j-i];
					if(arr[i][j] > mod) arr[i][j] -= mod;
					continue;
				}
				for(int l=1; l<=j-i-1; l++){
					long long temp = arr[k][l] * arr[i-k-1][j-i-l];
					temp %= mod;
					temp *= C(i-1, k);
					temp %= mod;
					arr[i][j] += temp;
					if(arr[i][j] > mod) arr[i][j] -= mod;
				}
			}
		}
	}
	printf("%d\n", arr[N][K]);
}
