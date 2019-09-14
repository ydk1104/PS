#include<stdio.h>

int ans,cnt[101];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x);
		if(cnt[x])ans++;
		else cnt[x]=1;
	}
	printf("%d",ans);
}
