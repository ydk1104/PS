#include<stdio.h>

int main(void){
	double a, b;
	scanf("%lf %lf", &a, &b);
	double v = 1-(a/b);
	int ans = 2*v;
	if(ans<0) ans *= -1;
	printf("%d", ans);
}
