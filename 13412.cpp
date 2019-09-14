#include<stdio.h>

int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b,a%b);
}

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		int N;
		scanf("%d", &N);
		int ans=0;
		for(int i=1; i*i<=N; i++){
			if(N%i) continue;
			if(gcd(i, N/i) == 1) ans++;
		}
		printf("%d\n", ans);
	}
}
