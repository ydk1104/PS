#include<stdio.h>
#include<stdlib.h>

typedef struct xy{
	int x;
	int y;
}xy;

xy po[100001];

int compare(const void *pa, const void *pb){
	xy *a = (xy*) pa;
	xy *b = (xy*) pb;
	if(a->x>b->x) return 1;
	if(a->x==b->x){
		if(a->y > b->y) return 1;
	}
	return -1;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d %d", &po[i].x, &po[i].y);
	}
	qsort(po, N, sizeof(xy), compare);
	for(int i=0; i<N; i++){
		printf("%d %d\n", po[i].x, po[i].y);
	}
}
