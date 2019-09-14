#include<stdio.h>
#define ll long long

int main(void){
	int N;
	scanf("%d", &N);
	ll sum=0, ans=0;
	for(int x=0;N--;){//scanf("%d",&x)){
		scanf("%d",&x);
		ans+=x*sum;
		sum+=x;
	}
	printf("%lld", ans);
	
}
