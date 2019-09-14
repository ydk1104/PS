#include<stdio.h>

int gcd(int a, int b){
	if(a==b) return a;
	if(a==0) return b;
	if(b==0) return a;
	if(a>b){
		a = a % b;
		return gcd(a, b);
	}
	else{
		b = b % a;
		return gcd(a, b);
	}
}

int main(void){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		int a, b;
		scanf("%d %d", &a, &b);
		int L = a / gcd(a,b) * b;
		printf("%d\n", L);
	}
}
