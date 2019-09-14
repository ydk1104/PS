#include<stdio.h>
#include<algorithm>
#include<math.h>

int a[5000001];
long long sum;

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	std::sort(a,a+N);
	long long ans = ceil((double)sum/N-0.5);
	printf("%d %lld",a[(N-1)/2], ans);
}
