#include<stdio.h>

int main(void){
	int N, L, K, ans=0;
	int a[101], b[101];
	scanf("%d %d %d", &N, &L, &K);
	for(int i=0; i<N; i++){
		scanf("%d %d", &a[i], &b[i]);
		if(K && b[i]<=L) ans+=140, K--, a[i]=L+1;
	}
	for(int i=0; i<N; i++){
		if(K && a[i]<=L) ans+=100, K--;
	}
	printf("%d",ans);
}
