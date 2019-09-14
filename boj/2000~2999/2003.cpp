#include<stdio.h>

int main(void){
	int N, M, sum=0, left=0, ans=0, a[10001];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		scanf("%d", &a[i]);
		sum += a[i];
		while(sum>M){
			sum-=a[left++];
		}
		if(sum==M){
			ans++;
			sum-=a[left++];
		}
	}
	printf("%d", ans);
}
