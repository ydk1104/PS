#include<stdio.h>

int dp[502][502];
int map[502][502];

int max2(int a, int b){
	if(a>b) return a;
	return b;
}

int max4(int a, int b, int c, int d){
	if(a<b) a=b;
	if(c<d) c=d;
	if(a<c) return c;
	return a;
}

int panda(int x, int y, int num){
	if(num>=map[x][y]){
		return 0;
	}	
	if(dp[x][y] >= 0){
		return dp[x][y];
	}
	dp[x][y] = max4(
	panda(x+1, y, map[x][y]),
	panda(x-1, y, map[x][y]),
	panda(x, y+1, map[x][y]),
	panda(x, y-1, map[x][y])
	)+1;
	return dp[x][y];
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			scanf("%d", &map[i][j]);
		}
	}
	for(int i=0; i<=N+1; i++){
		for(int j=0; j<=N+1; j++){
			dp[i][j] = -1;
		}
	}
	int ans = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			ans = max2(ans, panda(i, j, 0));
		}
	}
	printf("%d", ans);
	return 0;
}
