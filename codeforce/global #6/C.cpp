#include<stdio.h>

int N, M;

long long gcd(long long a, long long b){
	return b?gcd(b,a%b):a;
}

long long lcm(long long a, long long b){
	return a/gcd(a,b)*b;
}

int main(void){
	scanf("%d %d", &N, &M);
	if(N==1 && M==1){
		printf("0");
		return 0;
	}
	if(M == 1){
		for(int i=0; i<N; i++) printf("%d\n", i+2);
		return 0;
	}
	long long a[1001], b[1001];
	for(long long i=0; i<N; i++) a[i] = i+1;
	for(long long i=0; i<M; i++) b[i] = N+i+1;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			printf("%lld ", a[i]*b[j]);
		}
		printf("\n");
	}
}
