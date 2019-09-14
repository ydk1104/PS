#include<stdio.h>

int main(void){
	int N, K;
	scanf("%d %d", &N, &K);
	int ans=0;
	for(int i=1; i<=N; i++) ans=(ans+K)%i;
	printf("%d",ans+1);
}
