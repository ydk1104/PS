#include<stdio.h>

int main(void){
	int N, M, K, ans=0;
	scanf("%d %d %d", &N, &M, &K);
	while(N>1 && M>0 && (N+M-3)>=K){
		N-=2;
		M-=1;
		ans+=1;
	}
	printf("%d", ans);
}
