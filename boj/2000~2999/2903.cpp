#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	int ans=2;
	for(int i=1; i<=N; i++) ans+=ans-1;
	printf("%d", ans*ans);
}
