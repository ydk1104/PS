#include<stdio.h>
#define INF 1000000000

typedef struct Bus{
	int start;
	int end;
	int cost;
}B;

B bus[6001];
int map[501];

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=2; i<=N; i++){
		map[i] = INF;
	}
	for(int i=1; i<=M; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		bus[i].start = a;
		bus[i].end = b;
		bus[i].cost = c;
	}
	int flag = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if(map[bus[j].start] != INF){
				if(map[bus[j].end] > map[bus[j].start] + bus[j].cost){
					map[bus[j].end] = map[bus[j].start] + bus[j].cost;
					if(i==N) flag=1;
				}
			}
		}
	}
	if(flag) printf("-1");
	else{
		for(int i=2; i<=N; i++){
			if(map[i] == INF) printf("-1");
			else printf("%d", map[i]);
			printf("\n");
		}
	}
}
