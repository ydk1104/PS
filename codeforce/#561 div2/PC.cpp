#include<stdio.h>
#include<algorithm>

int a[200001];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	for(int i=0; i<N; i++) if(a[i]<0) a[i]=-a[i];
	std::sort(a, a+N);
	int left=0;
	long long ans=0;
	for(int i=0; i<N; i++){
		while(a[i]>a[left]*2) left++;
		ans+=i-left;
		
	}
	printf("%lld",ans);
}
