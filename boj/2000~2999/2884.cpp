#include<stdio.h>

int main(void){
	int a,b;
	scanf("%d%d",&a,&b);
	b-=45;
	if(b<0) a-=1,b+=60;
	if(a<0) a+=24;
	printf("%d %d",a,b);
}
