#include<stdio.h>

int main(void){
	char s[111] = {'0','0',};
	scanf("%s", s+2);
	int len = 0;
	while(s[len+2]) len++;
	char* p = s+2;
	if(len%3) p -= 3-(len%3);
	for(; *p; p+=3){
		printf("%d", ((*p)-'0')*4 + ((*(p+1))-'0')*2 + (*(p+2))-'0');
	}
}
