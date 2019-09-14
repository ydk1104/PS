#include<stdio.h>
#include<algorithm>

int main(void){
	int N, M, ta, tb, k;
	scanf("%d %d %d %d %d", &N, &M, &ta, &tb, &k);
	int a[200001], b[200001];
	for(int i=0; i<N; i++){
		scanf("%d", &a[i]);
	}
	for(int i=0; i<M; i++){
		scanf("%d", &b[i]);
	}
	int ans=0;
	if(k>=N || k>=M) printf("-1");
	else{
		int right=0;
		for(int i=0; i<=k; i++){
			int now = a[i]+ta;
			while(b[right]<now) right++;
			if(right+k-i>M){
				printf("-1");
				return 0;
			}
			ans=std::max(ans, b[right+k-i]+tb);
		}
		printf("%d",ans);
	}
}
