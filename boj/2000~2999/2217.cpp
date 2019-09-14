#include<stdio.h>
#include<algorithm>

int main(void){
	int N, a[100001];
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	std::sort(a, a+N);
	int ans = 0;
	for(int i=0; i<N; i++){
		ans = std::max(ans, a[i]*(N-i));
	}
	printf("%d", ans);
}
