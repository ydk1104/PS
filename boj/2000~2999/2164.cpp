#include<stdio.h>

int main(void){
	int N;
	scanf("%d",&N);
	int ans=0;
	for(int i=1; i<=N; i++) ans=(ans+2)%i;
	printf("%d",ans?ans:N);
}
