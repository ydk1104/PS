#include<stdio.h>
#define c 299792458.0

int main(void){
	double a,b;
	scanf("%lf %lf", &a, &b);
	double ans = (a+b)/(1+a*b/c/c);
	printf("%.10f", ans);
}
