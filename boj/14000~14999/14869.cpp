#include<stdio.h>
#define min(a,b) (((((a)<(b)) && ((a)>0)) || (b<=0)) ? (a) : (b))

int N, M, S, E, T;
int cook[3001][3001];
int no[3001];
int dp[3001][3001];

int DFS(int now, int cnt, int str){
	if(cnt == M) return 0;
	if(dp[now][cnt] != -1) return dp[now][cnt];
	if(str<S) return dp[now][cnt] = DFS(now, cnt+1, str+1)+cook[now][cnt+1];
	else if(str<E){
		for(int i=1; i<=N; i++){
			dp[now][cnt] = DFS(i, cnt+1, str+1)+cook[now][cnt+1];
			if((i != no[now]) && (i != now)){
				dp[now][cnt] = min(dp[now][cnt], DFS(i, cnt+1, 1)+cook[i][cnt+1]+T);
			}
		}
	}
	else{
		for(int i=1; i<=N; i++){
			if((now != no[i]) && (i != now)){
				dp[now][cnt] = min(dp[now][cnt], DFS(i, cnt+1, 1)+cook[i][cnt+1]+T);
			}
		}
	}
	return dp[now][cnt];
}

int main(void){
	scanf("%d %d %d %d %d", &N, &M, &S, &E, &T);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			scanf("%d", &cook[i][j]);
			dp[i][j] = -1;
		}
		dp[i][0] = -1;
	}
	for(int i=1; i<=N; i++){
		scanf("%d", &no[i]);
	}
	int ans = 0;
	for(int i=1; i<=N; i++){
		ans = min(ans, DFS(i, 0, 0));
	}
	printf("%d", ans);
}
