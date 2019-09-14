#include<stdio.h>

int main(void){
	int N;
	scanf("%d",&N);
	int a=0;
	while(N>1) a|=N%2,N/=2;
	printf("%d",!a);
}
