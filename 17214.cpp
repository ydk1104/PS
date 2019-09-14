#include<stdio.h>

int main(void){
	int a, b=1;
	scanf("%dx+%d", &a, &b);
	a/=2;
	if(a==1) a=0;
	if(b==1) b=0;
	printf("%dxx+%dx+W",a/2,b);
}
