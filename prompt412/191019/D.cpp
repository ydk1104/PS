#include<stdio.h>
#include<algorithm>

int light[3000];
int ans;

int dfs(int now){
	if(!light[now] && now!=1) return 0;
	int left = dfs(now*2) + light[now*2];
	int right = dfs(now*2+1) + light[now*2+1];
	ans += std::max(left,right) - std::min(left,right);
	return std::max(left,right);
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<((1<<(N+1))-2); i++){
		scanf("%d", &light[i+2]);
	}
	dfs(1);
	printf("%d", ans);
}
