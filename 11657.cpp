#include<stdio.h>
#include<vector>
#define INF 1000000000

typedef struct Bus{
	int start;
	int end;
	int cost;
}B;

std::vector<B> bus[501];
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
		bus[a].push_back({a,b,c});
	}
	int flag = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			for(auto k : bus[j]){
				if(map[k.start] != INF){
					if(map[k.end] > map[k.start] + k.cost){
						map[k.end] = map[k.start] + k.cost;
						if(i==N) flag = 1;
					}
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
