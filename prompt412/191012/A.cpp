#include<stdio.h>

int a[101], ans;

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	a[0] = -2e9;
	for(int i=1; i<=N; i++){
		scanf("%d", &a[i]);
		if(i==1) ans=2;
		else if(a[i] - a[i-1] > M*2) ans+=2;
		else if(a[i] - a[i-1] == M*2) ans++;
	}
	printf("%d", ans);
}
