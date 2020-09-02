#include<stdio.h>

long long a,b,c,d;
long long ans;

int gcd(int a, int b){
	if(b) return gcd(b, a%b);
	return a;
}

void solve(int x, int y){
	long long ax = ((a-1)/x+1);
	long long bx = (b/x);
	long long cy = ((c-1)/y+1);
	long long dy = (d/y);
	if(ax < cy) ax = cy;
	if(bx > dy) bx = dy;
	if(ax <= bx) ans += bx - ax + 1;
}

int main(void){
	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
	long long x,y;
	for(int i=1; i<=999; i++){
		for(int j=1; j<=999-i; j++){
			if(gcd(i, j) == 1){
				solve(i, j);
			}
		}
	}
	printf("%lld", ans);
}
