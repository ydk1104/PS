#include<stdio.h>
#define ll long long int

int main(void){
	int N;
	scanf("%d", &N);
	ll sum=0;
	ll ans=0;
	ll a[100001];
	for(int i=0; i<N; i++){
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	for(int i=0; i<N; i++){
		ans += (sum-a[i]) * a[i];
	}
	printf("%lld", ans/2);
}
