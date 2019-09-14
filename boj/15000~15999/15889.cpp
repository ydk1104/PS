#include<stdio.h>
#include<stdlib.h>

typedef struct po{
	int x;
	int r;
	int check;
}po;

po sol[100001];

int compare(const void *a, const void *b){
	po *pa = (po*)a;
	po *pb = (po*)b;
	if(pa->x > pb->x) return 1;
	if(pa->x == pb->x) return 0;
	return -1;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &sol[i].x);
	}
	for(int i=0; i<N-1; i++){
		scanf("%d", &sol[i].r);
	}
	qsort(sol, N, sizeof(po), compare);
	sol[0].check = 1;
	int max = 0;
	for(int i=0; i<N-1; i++){
		if(sol[i].check){
			for(int j=max+1; sol[i].x+sol[i].r>=sol[j].x; j++){
				sol[j].check = 1;
				max++;
			}
		}
	}
	if(sol[N-1].check){
		printf("권병장님, 중대장님이 찾으십니다");
	}
	else{
		printf("엄마 나 전역 늦어질 것 같아");
	}
}
