#include<stdio.h>

int a[1001];
int up[1001][1001];
int down[1002][1001];
	
int max(int a, int b){
	if(a>b) return a;
	return b;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1;i<=N;i++){
		scanf("%d", &a[i]);
		int t = 0;
		int u = 0;
		for(int j=1; j<i; j++){
			up[i][j] = up[i-1][j];
			if(a[i]>a[j]){
				t = max(t, up[i][j]);
			}
			u = max(u, up[i][j]);
		}
		up[i][i] = t+1;
		up[i][0] = max(u, t+1);
	}
	for(int i=N; i>=1; i--){
		int t = 0;
		int u = 0;
		for(int j=N; j>i; j--){
			down[i][j] = down[i+1][j];
			if(a[i]>a[j]){
				t = max(t, down[i][j]);
			}
			u = max(u, down[i][j]);
		}
		down[i][i] = t+1;
		down[i][0] = max(u, t+1);
	}
	int ans = 0;
	for(int i=1; i<=N; i++){
		ans = max(ans, up[i][0] + down[i][0]);
	}
	printf("%d", ans-1);
}
