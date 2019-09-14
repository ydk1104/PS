#include<stdio.h>

int main(void){
	int a, b;
	int c;
	scanf("%d %d\n%d", &a, &b, &c);
	int ans = a+b;
	if(ans>=c*2) ans -= c*2;
	printf("%d", ans);
}
