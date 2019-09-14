#include<stdio.h>

int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}

int main(void){
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	a = a*d + b*c;
	b = b*d;
	int G = gcd(a, b);
	a /= G;
	b /= G;
	printf("%d %d", a, b);
}
