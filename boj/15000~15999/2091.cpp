#include<stdio.h>

int dp[10031];
int ans[4][10031];

int main(void){
	int N;
	scanf("%d", &N);
	int a[4];
	for(int i=0; i<4; i++) scanf("%d",&a[i]);
	int c[4] = {1,5,10,25};
	for(int i=0; i<4; i++){
		if(a[i]) dp[c[i]]=1, ans[i][c[i]]=1;
	}
	for(int i=0; i<4; i++){
		for(int j=0; j<N; j++){
			if(dp[j] && dp[j+c[i]]<dp[j]+1 && ans[i][j]<a[i]){
				dp[j+c[i]] = dp[j]+1;
				for(int k=0; k<4; k++) ans[k][j+c[i]]=ans[k][j];
				ans[i][j+c[i]]++;
			}
		}
	}
	for(int i=0; i<4; i++) printf("%d ",ans[i][N]);
}
