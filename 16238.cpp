#include<stdio.h>
#include<algorithm>

int main(void){
	int N;
	scanf("%d", &N);
	int a[1001];
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	std::sort(a, a+N);
	int ans=0;
	int sum=0;
	for(int i=0; i<N; i++){
		sum += a[N-i-1]-i;
		ans = sum>ans?sum:ans;
	}
	printf("%d", ans);
}
