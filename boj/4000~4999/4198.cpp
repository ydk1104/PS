#include<stdio.h>
#define max(a,b) ((a)>(b) ? (a) : (b))

int N, ans;
int train[2001];
int dp[2001][2];
int cnt;

int BS(int com, int left, int right, int ta){
	int mid = (left+right+1)/2;
	if(left >= right) return right;
	if(com){
		if((dp[mid][com] == 0 || dp[mid][com]>ta) && dp[mid-1][com]<ta) return mid;
		if((dp[mid][com] == 0 || dp[mid][com]>ta )&& dp[mid-1][com]>ta) return BS(com, left, mid-1, ta);
		return BS(com, mid+1, right, ta);
	}
	if(dp[mid][com]<ta && dp[mid-1][com]>ta) return mid;
	if(dp[mid][com]<ta && dp[mid-1][com]<ta) return BS(com, left, mid-1, ta);
	return BS(com, mid+1, right, ta);
}

int main(void){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &train[i]);
	}
	for(int i=1; i<=N; i++){
		int temp = 0;
		for(int k=0; k<=1; k++){
			cnt = 1;
			dp[0][k] = train[i];
			for(int j=i+1; j<=N; j++){
				if((!k) && train[i]<train[j]) continue;
				if(k && train[i]>train[j]) continue;
				int p = BS(k, 1, cnt, train[j]);
				if(!dp[p][k]) cnt++;
				dp[p][k] = train[j];
			}
			temp += cnt;
			for(; cnt>=0; cnt--){
				dp[cnt][k] = 0;
			}
		}
		ans = max(ans, temp);
	}
	printf("%d", ans-1);
}
