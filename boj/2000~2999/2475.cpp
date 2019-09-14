#include<stdio.h>

int main(void){
	int x, sum=0;
	for(int i=0; i<5; i++){
		scanf("%d", &x);
		sum += x*x;
	}
	printf("%d", sum%10);
}
