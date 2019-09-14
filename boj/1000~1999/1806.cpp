#include<stdio.h>
#define min(a,b) ((a)<(b) ? (a) : (b))
#define INT_MAX 1000000

int main(void){
	int N, S;
	int num[100001];
	int sum[100001] = {0, };
	int cnt[100001] = {0, };
	int ans = INT_MAX;
	scanf("%d %d", &N, &S);
	for(int i=1; i<=N; i++){
		scanf("%d", &num[i]);
		sum[i] = num[i] + sum[i-1];
		cnt[i] = 1 + cnt[i-1];
        if(sum[i]>=S) ans = min(ans, cnt[i]);
		while(sum[i]-num[i-cnt[i]+1]>=S){
			sum[i] -= num[i-cnt[i]+1];
			cnt[i]--;
			ans = min(ans, cnt[i]);
		}
	}
	if(ans == INT_MAX) printf("0");
	else printf("%d", ans);
}
