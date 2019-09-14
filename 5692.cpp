#include<stdio.h>

int main(void){
	int N=1;
	while(scanf("%d", &N),N){
		int now=1, i=2, ans=0;
		while(N) ans+=(N%10)*now, N/=10, now*=i, i++;
		printf("%d\n", ans);
	}
}
