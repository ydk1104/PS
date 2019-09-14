#include<stdio.h>
#define min(a,b) a<b ? a : b

int min4(int a, int b, int c, int d){
	a = min(a, b);
	c = min(c, d);
	return min(a, c);
}

int main(void){
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	printf("%d", min4(x, w-x, y, h-y));
}
