#include<stdio.h>
#define Q_MAX 100000

typedef struct contents{
	int use;
	int exp;
	int prev;
}contents;

contents Q[Q_MAX+1];
contents con[1001];
int dp[10001][1001];
int prev[10001][1001];
int start, end, Qcnt;
int S, N;

void push(int use, int exp, int prev){
	Qcnt++;
	Q[end].use = use;
	Q[end].exp = exp;
	Q[end++].prev = prev;
	if(end>Q_MAX) end=0;
	return;
}

int main(void){
	scanf("%d", &S);
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d %d", &con[i].use, &con[i].exp);
	}
	int maxuse = 0;
	int maxlast = 0;
	push(0, 0, 0);
	for(int i=1; i<=N; i++){
		int nowcnt = Qcnt;
		for(int j=1; j<=nowcnt; j++){
			contents now = Q[start++];
			if(start>Q_MAX) start=0;
			Qcnt--;
			push(now.use, now.exp, now.prev);
			int newuse = now.use+con[i].use;
			int newexp = now.exp+con[i].exp;
			if(newuse>S) continue;
			if(dp[newuse][i] < newexp){
				prev[newuse][i] = now.prev;
				dp[newuse][i] = newexp;
				push(newuse, newexp, i);
				if(dp[maxuse][maxlast]<newexp){
					maxuse = now.use+con[i].use;
					maxlast = i;
				}
			}
		}
	}
	int ans[10001] = {0, };
	int cnt = 0;
	printf("%d\n", dp[maxuse][maxlast]);
	ans[cnt++] = maxlast;
	while(maxuse>0){
		ans[cnt] = prev[maxuse][maxlast];
		maxuse -= con[maxlast].use;
		maxlast = ans[cnt];
		cnt++;
	}
	cnt--;
	printf("%d\n", cnt);
	for(int i=0; i<cnt; i++){
		printf("%d ", ans[i]);
	}
	return 0;
}
