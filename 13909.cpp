#include<stdio.h>

int main(void){
	long long N;
	scanf("%d", &N);
	int ans=0;
	for(long long i=1; i*i<=N; i++) ans++;
	printf("%d",ans);
}
