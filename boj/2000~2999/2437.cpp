#include<stdio.h>
#include<stdlib.h>

int w[1001];

int compare(const void *a, const void *b){
	int* n1 = (int*)a;	
	int* n2 = (int*)b;
	if(*n1>*n2) return 1;
	if(*n1==*n2) return 0;
	return -1;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &w[i]);
	}
	qsort(w, N, sizeof(int), compare);
	int sum = 0;
	for(int i=0; i<N; i++){
		if(sum+1<w[i]){
			printf("%d", sum+1);
			return 0;
		}
		sum += w[i];
	}
	printf("%d", sum+1);
	return 0;
}
