#include<stdio.h>

int main(void){
	int a,b,c,d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int ans = d-a-b+c;
	if(ans<=0) ans=-1;
	if(c>a || c>b) ans=-1;
	printf("%d", ans);
}
