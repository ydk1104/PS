#include<stdio.h>

int main(void){
	int a,b,c,d,e;
	scanf("%d%d%d%d%d",&a,&b,&d,&c,&e);
	b=(b-1+c)/c;
	d=(d-1+e)/e;
	if(b<d) b=d;
	printf("%d",a-b);
}
