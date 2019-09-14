#include<stdio.h>
#include<algorithm>

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	int a[100001];
	long long ans=0;
	long long sum=0;
	for(int i=0; i<N; i++){
		if(i>=M) sum-=a[i-M];
		scanf("%d",&a[i]);
		sum+=a[i];
		ans=ans>sum?ans:sum;
	}
	printf("%lld",ans);
}

