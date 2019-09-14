#include<stdio.h>

struct uf{
	int value;
	uf* pa;
}map[251][251];

int cnt;

uf* find(uf* x){
	if(x->pa == x) return x;
	return x->pa=find(x->pa);
}

void merge(uf* x, uf* y){
	if(x->value * y->value == 0) return;
	x = find(x);
	y = find(y);
	if(x==y) return;
	cnt--;
	y->pa = x;
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	int dx[4] = {1, -1, 0, 1}, dy[4] = {0, 1, 1, 1};
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			scanf("%d", &map[i][j].value);
			map[i][j].pa = &map[i][j];
			cnt+=map[i][j].value;
			for(int k=0; k<4; k++) merge(&map[i][j], &map[i-dy[k]][j-dx[k]]);
		}
	}
	printf("%d", cnt);
}
