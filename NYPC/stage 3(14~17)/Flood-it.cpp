#include<stdio.h>

typedef struct set{
	int cnt;
	int color;
	set* num;
}set;

set uf[1001][1001];
int change[1001];

set* find(set *x){
	if(x->num==x) return x;
	return x->num = find(x->num);
}

void merge(set *a, set *b){
	set* x = find(a);
	set* y = find(b);
	if(x==y) return;
	x->cnt += y->cnt;
	y->num = x;
}

int check(set *a, set *b){
	a = find(a);
	b = find(b);
	if((a!=b) && (a->color == b->color)) return 1;
	return 0;
}

int main(void){
	int N, K;
	scanf("%d %d", &N, &K);
	for(int i=1; i<=K; i++){
		scanf("%d", &change[i]);
	}
	for(int i=0; i<=N; i++){
		for(int j=0; j<=N; j++){
			uf[i][j].color = -1;
			uf[i][j].cnt = -1;
			uf[i][j].num = &uf[i][j];
		}
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			scanf("%d", &uf[i][j].color);
		}
	}
	change[0] = uf[1][1].color;
	for(int k=0; k<=K; k++){
		set *temp = find(&uf[1][1]);
		temp->color = change[k];
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				if(check(&uf[i][j], &uf[i-1][j])) merge(&uf[i][j], &uf[i-1][j]);
				if(check(&uf[i][j], &uf[i][j-1])) merge(&uf[i][j], &uf[i][j-1]);
			}
		}
	}
	set* ans = find(&uf[1][1]);
	printf("%d", -ans->cnt);
}
