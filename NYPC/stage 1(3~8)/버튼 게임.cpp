#include<stdio.h>

int gcd(int a, int b){
	if(a%b==0) return b;
	if(b%a==0) return a;
	if(a>b) return gcd(a%b, b);
	return gcd(a, b%a);
}

int main(void){
	int a, b;
	scanf("%d %d", &a, &b);
	int flag = 0;
	if(a*b==0){
		if(a!=1) flag = 1;
	}
	else if(gcd(a,b) != 1) flag = 1;
	if(flag){
		printf("IMPOSSIBLE");
	}
	else printf("POSSIBLE");
	return 0; 
} 
