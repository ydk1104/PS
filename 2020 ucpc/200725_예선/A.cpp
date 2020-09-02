#include<iostream>

int main(void){
	int a,b,c,d,e,f;
	std::cin >> a >> b >> c >> d >> e >> f;
	int ka = a*d, kb = b*d, kc = c*d;
	int ld = a*d, le = a*e, lf = a*f;
	int bb = kb-le, cc = kc-lf;
	int y = cc / bb;
	int x = (c - b * y) / a;
	printf("%d %d", x,y);
}
