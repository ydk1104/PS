#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	if(N==1) printf("0");
	else printf("%d", (N+1)/2);
}
