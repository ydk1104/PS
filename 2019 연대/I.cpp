#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	N%=4;
	if(N==3) printf("2");
	else printf("1");
}
