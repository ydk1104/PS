#include<stdio.h>

int a[100010];
int s[100010];

int main(void){
	int N;
	scanf("%d", &N);
	a[0] = -2000000000;
	a[N+1] = 2000000000;
	for(int i=1; i<=N; i++){
		scanf("%d", &a[i]);
		s[i] = s[i-1] + (a[i-1]<=a[i]);
	}
	s[N+1] = s[N] + 1;
	int ans=0;
	for(int i=1; i<=N; i++){
		if((s[i-1] - s[0] == i-1 ) && (s[N]-s[i+1] == N-i-1) && a[i-1]<=a[i+1]){
			ans++;
		}
	}
//	for(auto i : s) printf("%d ",i);
	printf("%d", ans);
	
}
