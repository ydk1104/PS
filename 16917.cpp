#include<stdio.h>

int main(void){
	int a, b, c, d, e;
	int ans=0;
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	if(a+b > c+c){
		int temp;
		if(d>e) temp=e;
		else temp=d;
		d -= temp;
		e -= temp;
		ans += temp*2*c;
	}
	if(a > c+c) a = c+c;
	ans += a*d;
	if(b > c+c) b = c+c;
	ans += b*e;
	printf("%d", ans);
}
