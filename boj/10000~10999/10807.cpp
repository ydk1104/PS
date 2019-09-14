#include<stdio.h>

int cnt[201];

int main(void){
	int N;
	for(scanf("%d", &N); N--;){
		int x;
		scanf("%d", &x);
		cnt[x+100]++;
	}
	scanf("%d",&N);
	printf("%d",cnt[N+100]);
}
