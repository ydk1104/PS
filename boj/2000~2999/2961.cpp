#include<stdio.h>
#define abs(x) (x>0) ? (x) : -(x)
#define min(a,b) (a>b) ? (b) : (a)

int N;
int s[11], b[11];

int dfs(int now, int scon, int bsum, int check){
	if(now>N){
		if(check>0) return(abs(scon-bsum));
		return 2000000000;
	}
	int num1 = dfs(now+1, scon, bsum, check);
	scon *= s[now];
	bsum += b[now];
	int num2 = dfs(now+1, scon, bsum, check+1);
	scon /= s[now];
	bsum -= b[now];
	return min(num1, num2);
}

int main(void){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d %d", &s[i], &b[i]);
	}
	int ans = dfs(1, 1, 0, 0);
	printf("%d", ans);
}
