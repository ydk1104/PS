#include<stdio.h>

int main(void){
	int a, b, c;
	while(1){
		scanf("%d %d %d", &a, &b, &c);
		if(!a) break;
		if(a>c){
			a^=c; c^=a; a^=c;
		}
		if(b>c){
			b^=c; c^=b; b^=c;
		}
		printf("%s\n", a*a+b*b==c*c?"right":"wrong");
	}
}
