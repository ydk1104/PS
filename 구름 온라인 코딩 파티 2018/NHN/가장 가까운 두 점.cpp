#include<stdio.h>
#include<stdlib.h>
#define min(a,b) (minus[a] > minus[b]) ? b : a 

int compare(const void *a, const void *b){
	long long int* p1 = (long long int*) a;
	long long int* p2 = (long long int*) b;
	if(*p1 > *p2) return 1;
	if(*p1 == *p2) return 0;
	return -1;
}

int main(void){
	int N;
	long long int dot[10] = {0, };
	long long int minus[9] = {0, };
	int ans = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%lld", &dot[i]);
	}
	qsort(dot, N, sizeof(long long int), compare);
	for(int i=0; i<N-1; i++){
		minus[i] = dot[i+1] - dot[i];
		ans = min(ans, i);
	}
	printf("%lld %lld", dot[ans], dot[ans+1]);
}
