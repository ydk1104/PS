#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))

char map[20][20];
int ans=1;
int check[20], N;

void BT(int now, int cnt, int cost){
	check[now]++;
	ans = max(ans, cnt);
	for(int i=1; i<=N; i++){
		if(map[now][i]>=cost && !check[i]){
			BT(i, cnt+1, map[i][now]);
		}
	}
	check[now]--;
}

int main(void){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%s", &map[i]);
	}
	BT(1, 1, 0);
	printf("%d", ans);
}
