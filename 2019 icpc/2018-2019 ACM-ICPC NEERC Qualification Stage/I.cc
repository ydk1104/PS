#include<stdio.h>
#include<algorithm>
 
int a[10001];
 
int main(void){
	int N; scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	std::sort(a, a+N);
	printf("%d",1-N+a[N-1]-a[0]);
}

