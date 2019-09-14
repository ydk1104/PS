#include<stdio.h>

int gcd(int a, int b){
	if(a==0) return b;
	if(b==0) return a;
	if(a==b) return a;
	if(a>b) return gcd(a%b, b);
	return gcd(a, b%a);
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	int max = gcd(M, N);
	int min = N / max * M;
	printf("%d\n%d", max, min);
}
