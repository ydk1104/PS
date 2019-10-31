#include<stdio.h>
 
int a[200001];
int b[200001];
 
int main(void){
	int N, K;
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++){
		scanf("%d %d", &a[i], &b[i]);
	}
	a[N] = 2e9;
	a[N] += 10000;
	int now = a[0] + K;
	int left = 0, right = 0, ans=0;
	while(left < N){
//		printf("test : %d %d\n", left, now);
		while(now > a[right]){
		
			now += b[right]-a[right];
//			printf("%d %d %d %d %d\n", now, right, a[right], b[right], b[right]-a[right]);
			right++;
		}
		if(ans < now-a[left]) ans = now-a[left];
		now += a[left+1] - b[left];
		left++;
	}
	printf("%d", ans);
}
