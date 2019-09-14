#include<stdio.h>

int main(void){
	long long int max=1;
	for(int i=1; i<=18; i++) max*=10;
	printf("%lld", max);
}
