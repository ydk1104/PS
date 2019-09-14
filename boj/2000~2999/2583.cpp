#include<stdio.h>
#include<stdlib.h>

typedef struct set{
	int x;
	int y;
	int check;
	set* root;
	int num;
}set;

int N, M, K;
set map[102][102];
int ans[10001];
int cnt;

int compare(const void *pa, const void *pb){
	int *a = (int*) pa;
	int *b = (int*) pb;
	if(*a < *b) return 1;
	return -1;
}

set* find(set *x){
	if(x->root == NULL) return x;
	return x->root = find(x->root);
}

void merge(set *a, set *b){
	set *ra = find(a);
	set *rb = find(b);
	if(ra == rb) return;
	ra->num += rb->num;
	rb->root = ra;
}

void check(set *a, set *b){
	if(b->x==0 || b->y==0) return;
	if(b->check) return;
	b->check = 1;
	merge(a, b);
	check(b, b+102);
	check(b, b-102);
	check(b, b+1);
	check(b, b-1);
}

int main(void){
	scanf("%d %d %d", &N, &M, &K);
	for(int i=1; i<=K; i++){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for(int i=y1+1; i<y2+1; i++){
			for(int j=x1+1; j<x2+1; j++){
				map[i][j].check = 1;
			}
		}
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if(!map[i][j].check){
				map[i][j].num = -1;
			}
			map[i][j].x = i;
			map[i][j].y = j;
		}
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if(!map[i][j].check){
				check(&map[i][j], &map[i+1][j]);
				check(&map[i][j], &map[i-1][j]);
				check(&map[i][j], &map[i][j+1]);
				check(&map[i][j], &map[i][j-1]);
				ans[cnt++] = find(&map[i][j])->num;
			}
		}
	}
	printf("%d\n", cnt);
	qsort(ans, cnt, sizeof(int), compare);
	for(int i=0; i<cnt; i++){
		printf("%d ", -ans[i]);
	}
}
