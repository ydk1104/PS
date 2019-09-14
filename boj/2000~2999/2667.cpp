#include<stdio.h>
#include<stdlib.h>

typedef struct Pa{
	int x;
	int y;
	int num;
	Pa* pa;
}Pa;

Pa rt[30][30];
int map[30][30];
int ans[1000];
int cnt;

int compare(const void *pa, const void *pb){
	int* a = (int*) pa;
	int* b = (int*) pb;
	if(*a > *b) return 1;
	return -1;
}

Pa* find(Pa* x){
	if(x->pa == NULL) return x;
	return x->pa = find(x->pa);
}

void merge(Pa* a, Pa* b){
	if((b->x == 0) || (b->y == 0)) return;
	Pa *ra = find(a);
	Pa *rb = find(b);
	if(ra==rb) return;
	ra->num += rb->num;
	rb->pa = ra;
	merge(b, b+1);
	merge(b, b-1);
	merge(b, b+30);
	merge(b, b-30);
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			scanf("%1d", &map[i][j]);
			if(map[i][j]){
				rt[i][j].x = i;
				rt[i][j].y = j;
				rt[i][j].num = 1;
			}
		}
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(map[i][j] && rt[i][j].pa == NULL){
				merge(&rt[i][j], &rt[i+1][j]);
				merge(&rt[i][j], &rt[i-1][j]);
				merge(&rt[i][j], &rt[i][j+1]);
				merge(&rt[i][j], &rt[i][j-1]);
				ans[cnt++] = find(&rt[i][j])->num;				
			}
		}
	}
	qsort(ans, cnt, sizeof(int), compare);
	printf("%d\n", cnt);
	for(int i=0; i<cnt; i++){
		printf("%d\n", ans[i]);
	}
}
