#include<stdio.h>
#include<tuple>

char map[1002][1002];

int check(std::pair<int, int> x){
	return !map[x.first][x.second];
}

std::pair<int, int> operator +(std::pair<int, int> a, std::pair<int, int> b){
	return {a.first+b.first, a.second+b.second};
}

int main(void){
	int N, K;
	scanf("%d %d", &N, &K);
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) map[i][j] = 1;
	std::pair<int, int> now = {1,1};
	std::pair<int, int> move[4] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
	int type = 0;
	for(int i=1; i<K; i++){
		map[now.first][now.second] = 0;
		if(check(now + move[type])) type = (type+1)%4;
		now = now + move[type];
	}
	printf("%d %d", now.first, now.second);
}
