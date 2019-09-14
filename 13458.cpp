#include<stdio.h>

long long int N, a[1000001], B, C, ans;

int main(void){
	scanf("%lld", &N);
	for(int i=0; i<N; i++){
		scanf("%lld", &a[i]);
	}
	scanf("%lld %lld", &B, &C);
	for(int i=0; i<N; i++){
		if(a[i]<=B) ans++;
		else ans += (a[i]-B-1)/C+2;
	}
	printf("%lld", ans);
}
