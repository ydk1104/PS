#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	while(N--){
	int ans=0;
	for(int i=1; i<=N; i++) ans+=(N-1)/i+1; //printf("%d\n", ((N-1)/i+1));
	printf("\n%d %d ", N, ans);
//	printf("%d\n", N*N-N);
	}
}
