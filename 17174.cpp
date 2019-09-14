#include<stdio.h>

int main(void){
	int N, M, ans=0;
	scanf("%d %d", &N, &M);
	while(N){
		ans+=N;
		N/=M;
	}
	printf("%d", ans);
}
