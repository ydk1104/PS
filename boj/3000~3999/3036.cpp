#include<stdio.h>

int gcd(int a, int b){
	if(a==0) return b;
	if(b==0) return a;
	if(a>b) return gcd(a%b, b);
	return gcd(a, b%a);
}

int main(void){
	int N;
	scanf("%d", &N);
	int r[101];
	for(int i=1; i<=N; i++){
		scanf("%d", &r[i]);
	}
	for(int i=2; i<=N; i++){
		int temp = gcd(r[1], r[i]);
		printf("%d/%d\n", r[1]/temp, r[i]/temp);
	}
}
