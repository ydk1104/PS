#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b){
	int* pa = (int*) a;
	int* pb = (int*) b;
	return *pa>*pb;
}

int main(void){
	int T;
	scanf("%d", &T);
	for(; T>0; T--){
		int N, M, K;
		scanf("%d %d %d", &N, &M, &K);
		int a[21];
		for(int i=0; i<N; i++) scanf("%d", &a[i]);
		qsort(a, N, sizeof(int), compare);
		for(; K>0; K--){
			qsort(a, N, sizeof(int), compare);
			for(int i=0; i<3; i++) a[i]++;
		}
		int ans = a[N-1]/M + (a[N-1]%M>0);
		printf("%d\n", ans);
	}
}
