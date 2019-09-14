#include<stdio.h>
#include<algorithm>

long long a[100001];

bool cmp(long long a, long long b){
	return a>b;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%lld", &a[i]);
	std::sort(a, a+N, cmp);
	long long ans = 0;
	for(int i=0; i<N; i++){
		if(ans<(ans^a[i])) ans^=a[i];
	}
	printf("%lld",ans);
}
