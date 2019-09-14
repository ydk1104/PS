#include<stdio.h>
#define MAX 9999999
#define ll long long

int era[MAX+1];
ll p[MAX+1];
int cnt;

int main(void){
	p[cnt++] = 2;
	for(int i=3; i<MAX; i+=2){
		if(era[i]) continue;
		for(int j=3; i*j<MAX; j+=2){
			era[i*j]++;
		}
		p[cnt++]=i;
	}
	ll A, B;
	scanf("%lld%lld", &A, &B);
	ll ans=0;
	for(int i=0; i<cnt && p[i]*p[i]<=B; i++){
		ll now = p[i];
		while(now<=(A-1)/p[i]) now*=p[i];
		while(now<=B/p[i]) now*=p[i], ans++;
	}
	printf("%lld", ans);
}
