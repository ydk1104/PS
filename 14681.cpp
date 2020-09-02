#include<stdio.h>

int main(void){
	int x,y;
	scanf("%d %d", &x, &y);
	int ans = 0;
	if(x*y<0) ans |= 1;
	if(y<0) ans |= 2;
	printf("%d", ans+1);
}
