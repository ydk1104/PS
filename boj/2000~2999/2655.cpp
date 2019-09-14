#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a)>(b) ? (a) : (b))

typedef struct brick{
	int h;
	int cnt;
	int check;
	int prev;
	int num;
}brick;

typedef struct ahn{
	int a;
	int h;
	int n;
	int num;
}MAP;

int compare(const void *a, const void *b){
	MAP* pa = (MAP*) a;
	MAP* pb = (MAP*) b;
	if(pa->a < pb->a) return 1;
//	if(pa->a == pb->a) return 0;
	return -1;
}

int main(void){
	int N;
	int MAX = 1;
	scanf("%d", &N);
	MAP map[101];
	brick dp[101] = {0, };
	for(int i=1; i<=N; i++){
		scanf("%d %d %d", &map[i].a, &map[i].h, &map[i].n);
		map[i].num = i;
	}
	qsort(map+1, N, sizeof(MAP), compare);
	for(int i=1; i<=N; i++){
		dp[i].h = map[i].h;
		dp[i].check = map[i].h;
		dp[i].cnt = 1;
		dp[i].num = map[i].num;
		for(int j=1; j<i; j++){
			if(map[i].n<map[j].n){
				dp[i].h = max(dp[i].h, dp[j].h+map[i].h);
				if(dp[i].h>dp[i].check){
					dp[i].check = dp[i].h;
					dp[i].prev = j;
					dp[i].cnt = dp[j].cnt+1;
				}
			}
		}
		if(dp[MAX].h<dp[i].h){
			MAX = i;
		}
	}
	printf("%d\n", dp[MAX].cnt);
	while(MAX>0){
		printf("%d\n", dp[MAX].num);
		MAX = dp[MAX].prev;
	}
}
