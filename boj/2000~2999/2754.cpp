#include<stdio.h>
#include<map>

int main(void){
	char s[3];
	scanf("%s", &s);
	float a=float(69-s[0]);
	if(s[1]=='+') a+=0.3;
	if(s[1]=='-') a-=0.3;
	if(a<0) a=0;
	printf("%.1f", a);
}
