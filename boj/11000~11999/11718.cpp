#include<stdio.h>

int main(void){
	char s;
	while((s = getchar()) != EOF){
		printf("%c", s);
	}
	return 0;
}
