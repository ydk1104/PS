#include<stdio.h>
#include<stdlib.h>

typedef struct rectangle{
	int x1;
	int x2;
	int y1;
	int y2;
	int color;
	int end;
}re;

typedef struct tree{
	int sum;
	int cnt[4];
	int gap;
	int y;
};

int compare(const void *pa, const void *pb){
	re *a = (re*) pa;
	re *b = (re*) pb;
//	if(a->color != b->color) return a->color>b->color;
	return a->x1>b->x1;
}

int compare_y(const void *pa, const void *pb){
	tree *a = (tree*) pa;
	tree *b = (tree*) pb;
	return a->y>b->y;
}

re a[200001];
re line[400001];
tree segetree[1300001];

int check(int number){
	for(int i=1; i<=2; i++){
		if(segetree[number].cnt[i]==0) return 0;
	}
	if(segetree[number]cnt[3]>0) return 0;
	return 1;
}

void update(int start, int end, int now, int nowL, int nowR, int value, int color){
	if(nowR < start || end < nowL) return;
	if(nowL==start && nowR == end){
		segetree[now].cnt[color]++;
		if(check(now))
	}
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d %d %d %d %d", &a[i].x1, &a[i].x2, &a[i].y1, &a[i].y2, &a[i].color);
	}
	int size = 1;
	while(size<=N*2) size = size<<1;
	for(int i=0; i<N; i++){
		segetree[size+2*i].y = a[i].y1;
		segetree[size+2*i+1].y = a[i].y2;
		line[2*i] = a[i];
		line[2*i+1] = a[i];
		line[2*i].end = 1;
		line[2*i+1].x1 = a[i].x2;
		line[2*i+1].end = -1;
	}
	qsort(segetree+size, 2*N, sizeof(tree), compare_y);
	qsort(line, 2*N, sizeof(re), compare);
	long long int ans = 0;
	for(int i=0; i<2*N; i++){
//		if(segetree[1].sum > 0) ans += segetree[1] * (line[i].x1 - line[i-1].x1);
		update(line[i].y1, line[i].y2, 1, size, 2*size-1, line[i].end, line[i].color);
	}
	printf("%lld", ans);
}
