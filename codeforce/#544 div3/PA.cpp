#include<stdio.h>

int main(void){
	int a, b, c, d;
	scanf("%d:%d%d:%d", &a, &c, &b, &d);
	a=a+b;
	c+=d;
	c/=2;
	if(a%2) c+=30;
	a/=2;
	if(c>=60)c-=60, a+=1;
	if(a>=24)a-=24;
	printf("%02d:%02d", a, c);
}
