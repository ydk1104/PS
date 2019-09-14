#include<stdio.h>

int main(void){
	long long N;
	scanf("%lld", &N);
	if(N%7==0 || N%7==2) printf("CY");
	else printf("SK");
}
