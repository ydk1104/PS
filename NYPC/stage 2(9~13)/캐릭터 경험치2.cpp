#include<stdio.h>

typedef struct contents{
	int use;
	int exp;
	int last;
}contents;

contents con[1001];
contents dp[1001][10001] = {0, };
int prev[1001][10001] = {0, };
int S, N; 

int main(void){
	scanf("%d", &S);
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d %d", &con[i].use, &con[i].exp);
	}
	for(int i=1; i<=N; i++){
		for(int j=con[i].use; j<=S; j++){
			dp[i][j] = dp[i-1][j];
			prev[i][j] = prev[i-1][j];
			int prevuse = j-con[i].use;
			int newexp = dp[i-1][prevuse].exp+con[i].exp;
			if(dp[i][j].exp<newexp){
				dp[i][j].exp = newexp;
				dp[i][j].last = i;
				prev[i][j] = dp[i-1][prevuse].last;
			}
		}
	}
	int ans[10001] = {dp[N][S].last, };
	int cnt = 1;
	printf("%d\n", dp[N][S].exp);
	while(N>0){
		ans[cnt] = prev[N][S];
		S -= con[dp[N][S].last].use;
		N = ans[cnt];
		cnt++;
	}
	cnt--;
	printf("%d\n", cnt);
	for(int i=0; i<cnt; i++){
		printf("%d ", ans[i]);
	}
	return 0;
}
