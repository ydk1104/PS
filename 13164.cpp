#include<stdio.h>
#include<stdlib.h>

int h[300001];
int minus[300000];

int compare(const void *a, const void *b){
	int* pa = (int*) a;
	int* pb = (int*) b;
	if(*pa < *pb) return 1;
	if(*pa == *pb) return 0;
	return -1;
}

int main(void){
	int N, K;
	scanf("%d %d", &N, &K);
	for(int i=1; i<=N; i++){
		scanf("%d", &h[i]);
		if(i!=1){
			minus[i-2] = h[i]-h[i-1];
		}
	}
	long long int ans = 0;
	qsort(minus, N-1, sizeof(int), compare);
	for(int i=K-1; i<=N-1; i++){
		ans += minus[i];
	}
	printf("%lld", ans);
}
