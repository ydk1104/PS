#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	int sum=0;
	for(int i=1; i<=N; i++){
		if(N%i==0) sum += i;
	}
	printf("%d", sum*5-24);
}
