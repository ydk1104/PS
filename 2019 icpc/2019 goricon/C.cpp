#include<stdio.h>
#include<vector>
#include<algorithm>

int main(void){
	int N, M, D;
	scanf("%d %d %d", &N, &M, &D);
	std::vector<std::vector<int> > dp, arr;
	dp.resize(N+1);
	arr.resize(N+1);
	for(int i=0; i<=N; i++){
		dp[i].resize(M+1);
		arr[i].resize(M+1);
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%d", &arr[i][j]);
			dp[i][j] = -2e9;
		}
	}
	int ans = -2e9;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			for(int k=i+1; k<=i+D && k<N; k++){
				for(int l=j-D+(k-i); l<M && l<=j+(D-(k-i)); l++){
					if(l<0) continue;
					if(i==0) dp[k][l] = std::max(dp[k][l], arr[i][j] * arr[k][l]);
					dp[k][l] = std::max(dp[k][l], dp[i][j] + arr[i][j] * arr[k][l]);
					if(k==N-1) ans = std::max(ans, dp[k][l]);
				}
			}
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
//			printf("%d ",dp[i][j]);
		}
//		printf("\n");
	}
	printf("%d", ans);
}
