#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	if((N%4==0)&&(N%100)||(N%400==0)){
		printf("1");
	}
	else printf("0");
}
