#include<stdio.h>

int main(void){
#define int long long
	int N;
	scanf("%lld", &N);
	int ans=0;
	for(int i=1; i<=N;){
		int q=(N-1)/i;
		int r=(N-1)%i;
		if(!q) q=r+1;
		int next = r/q+1;
		ans+=(((N-1)/i)+1)*next;
		i+=next;
	}
	printf("%lld",ans);
}
