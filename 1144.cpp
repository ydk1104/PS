#include<stdio.h>
#include<algorithm>

struct uf{
	uf* pa;
	int value;
};

uf map[11][11];
int dp[11][11];
int ans=1000;

uf* find(uf *x){return x->pa ? x->pa = find(x->pa) : x;
}

void merge(uf *a, uf *b){
	a = find(a);
	b = find(b);
	if(a==b) return;
	if(a->value < 0 && b->value < 0){
		a->value += b->value;
		b->pa = a;
	}
	return;
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			scanf("%d", &map[i][j].value);
			merge(&map[i][j], &map[i-1][j]);
			merge(&map[i][j], &map[i][j-1]);
			ans = std::min(ans, map[i][j].value);
		}
	}
	printf("%d", ans);
}
