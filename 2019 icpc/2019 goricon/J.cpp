#include<stdio.h>

int main(void){
	long long N, K, min=1;
	scanf("%d %lld", &N, &K);
	int max = N;
	while(K){
		if(K >= max-min){
			printf("%d ",max);
			K -= max-min;
			max--;
		}
		else{
			printf("%d ",min++);
			N--;
		}
	}
	for(int i=min; i<=max; i++) printf("%d ",i);
}
