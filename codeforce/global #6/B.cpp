#include<stdio.h>

int N;

int main(void){
	scanf("%d", &N);
	while(N--){
		long long x;
		scanf("%lld", &x);
		if(x>14) x %= 14;
		else x += 14;
		printf("%s\n", (x>=1 && x<=6) ? "YES" : "NO", x);
	}
}
