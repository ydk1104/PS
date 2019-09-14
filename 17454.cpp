#include<stdio.h>

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		int a,b,c,d;
		scanf("%*d %*d %d %d %d %d", &a, &b, &c, &d);
		if(a>b || c>d || a*d+b*c>b*d) printf("GOD\n");
		else printf("KDH\n");
	}
}
