#include<stdio.h>

long long pow(long long N, long long cnt, long long M){
	long long pro = N;
	long long temp = 1;
	while(cnt){
		cnt%2 ? temp*=pro : 1;
		temp %= M;
		pro *= pro;
		pro %= M;
		cnt /= 2;
	}
	return temp;
}

int main(void){
	int T;
	for(scanf("%d", &T);T--;){
		long long N, M;
		scanf("%d %d", &N, &M);
		long long a = pow(N, N, M);
		long long b = pow(N, a, M);
		printf("%d %d\n", a, b);
	}
	
}
