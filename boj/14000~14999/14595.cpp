#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (a)>(b) ? (a) : (b)

typedef struct lr{
	int left;
	int right;
};

lr merge[5001];

int compare(const void *pa, const void *pb){
	lr* a = (lr*) pa;
	lr* b = (lr*) pb;
	if(a->left > b->left) return 1;
	return 0;
}

int main(void){
	int N;
	scanf("%d", &N);
	int M;
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		scanf("%d %d", &merge[i].left, &merge[i].right);
	}
	qsort(merge, M, sizeof(lr), compare);
	int left = merge[0].left;
	int right = merge[0].right;
	for(int i=1; i<M; i++){
		if(right>=merge[i].left) right = max(right, merge[i].right);
		else{
			N -= right-left;
			left = merge[i].left;
			right = merge[i].right;
		}
	}
	printf("%d", N-right+left);
}
