#include<stdio.h>
#define ll long long

ll N,M,a[1001],ans;

int main(void){
	scanf("%lld", &N);
	for(int i=0; i<N; i++) scanf("%lld", &a[i]);
	scanf("%lld", &M);
	for(int i=0; i<N; i++) if(a[i]) ans+=(a[i]-1)/M+1;
	printf("%lld", ans*M);
}
