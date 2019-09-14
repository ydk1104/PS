#include<stdio.h>

int gcd(int a, int b){return b?gcd(b,a%b):a;}
int a[101];

int main(void){
	int T;
	for(scanf("%d", &T);T--;){
		int N;
		long long ans=0;
		scanf("%d",&N);
		for(int i=0; i<N; i++){
			scanf("%d", &a[i]);
			for(int j=0; j<i; j++) ans+=gcd(a[i],a[j]);
		}
		printf("%lld\n", ans);
	}
}
