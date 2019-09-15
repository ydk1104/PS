#include<stdio.h>
#include<algorithm>

int main(void){
	int a,b,c,d,e;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	printf("%d ", e - a*(c-1) - b*(d-1) <= 0 ? 0 : std::min(e - a*(c-1) - b*(d-1), a+b));
	int ans=0;
	if(c>d){
		std::swap(a,b);
		std::swap(c,d);
	}
	ans += e/c > a ? a : e/c;
	e -= e/c > a ? a*c : e/c*c;
	ans += std::min(e/d, b);
	printf("%d", ans);
}
