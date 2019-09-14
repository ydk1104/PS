#include<stdio.h>
#define abs(x) (((x)>0) ? (x) : -(x))
#define min(a,b) (((a)<(b) && (a)!=0) ? (a) : (b))

typedef struct xy{
	int x;
	int y;
	int sum;
	int d;
}xy;

int distance(xy a, xy b){
	int d = abs(a.x-b.x) + abs(a.y-b.y);
	return d;
}

xy work[1003];
xy dp[2][1003][1003];

int main(void){
	int N, W;
	int d0, d1;
	scanf("%d\n%d", &N, &W);
	work[0].x = 1;
	work[0].y = 1;
	work[1].x = N;
	work[1].y = N;
	for(int i=2; i<=W+1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		work[i].x = a;
		work[i].y = b;
		work[i].d = distance(work[i-1], work[i]); // 저번지점과 현 지점 사이의 거리 
		work[i].sum = work[i-1].sum + work[i].d;
		if(i==2){
			work[i].sum = 0;
			d0 = distance(work[0], work[i]);
			d1 = distance(work[1], work[i]);
			dp[0][0][i].sum = d0;
			dp[1][0][i].sum = d1;
			for(int j=0; j<=1; j++){
				dp[j][1][i].sum = dp[j][0][i].sum;
			}
		}
		else{
			for(int j=0; j<=1; j++){
				dp[j][0][i].sum = dp[j][0][i-1].sum + work[i].d;
				dp[j][1][i].sum = dp[j][0][i].sum;
				for(int k=2; k<i-1; k++){
					dp[j][k][i].sum = dp[j][k][i-1].sum + work[i].d;
					dp[j][1][i].sum = min(dp[j][1][i].sum, dp[j][k][i].sum);
				}
				dp[j][i-1][i].sum = dp[1-j][0][i-1].sum + distance(work[1-j], work[i]);
				for(int k=2; k<i-2; k++){
					dp[j][i-1][i].sum = min(dp[j][i-1][i].sum,
					dp[1-j][k][i-1].sum+distance(work[k], work[i]));
				}
				dp[j][1][i].sum = min(dp[j][1][i].sum, dp[j][i-1][i].sum);		
			}
		}
	}
	int ans;
	printf("%d\n", ans = min(dp[0][1][W].sum, dp[1][1][W].sum));
	for(int i=W+1; i>=2; i--){
		for(int j=0; j<=1; j++){
			if(ans == work[i].d + )
		}
	}
}
