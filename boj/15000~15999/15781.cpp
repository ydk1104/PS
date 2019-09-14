#include<stdio.h>
#define max(a,b) ((a)>(b)) ? (a) : (b)

int main(void){
	int N, M, maxN=0, maxM=0;
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++){
		int temp;
		scanf("%d", &temp);
		maxN = max(maxN, temp);
	}
	for(int i=1; i<=M; i++){
		int temp;
		scanf("%d", &temp);
		maxM = max(maxM, temp);
	}
	printf("%d", maxN+maxM);
}
