#include<stdio.h>

int dp[31][11];

int find(int x, int y){
	if(dp[x][y]) return dp[x][y];
	if(x==0 || y==1) return 1;
	return find(x-1, y) + find(x, y-1);
}

int main(void){
	int a,b;
	scanf("%d %d", &a, &b);
	printf("%d", find(b-a, a));
}
