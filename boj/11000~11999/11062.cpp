#include<stdio.h>
#define max(a,b) a>b ? a : b

int memory[1001][1001][2];
int card[1001];
int sum[1001];

int dp(int left, int right, int turn){
	if(memory[left][right][turn%2]>0) return memory[left][right][turn%2];
	if(left == right) return card[left]; 
	memory[left][right][turn%2] = sum[right] - sum[left] + card[left];
	memory[left][right][(turn+1)%2] = memory[left][right][turn%2];
	memory[left][right][turn%2] +=
	max((0-dp(left+1, right, turn+1)), (0-dp(left, right-1, turn+1)));
	memory[left][right][(turn+1)%2] -= memory[left][right][turn%2];
	return memory[left][right][turn%2];
}

int main(void){
	int T;
	scanf("%d", &T);
	for(; T>0; T--){
		int N;
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			scanf("%d", &card[i]);
			for(int j=0; j<N; j++){
				memory[i][j][0] = 0;
				memory[i][j][1] = 0;
			}
			(i==0) ? sum[i]=card[i] : sum[i]=card[i]+sum[i-1];
		}
		int ans = dp(0, N-1, 0);
		printf("%d\n", ans);
	}
}
