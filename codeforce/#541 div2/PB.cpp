#include<stdio.h>
#define min(x,y) ((x)>(y)?(y):(x))
#define max(x,y) ((x)>(y)?(x):(y))

int main(void){
	int N;
	int x[10001], y[10001];
	int ans=1;
	x[0]=0, y[0]=0;
	int draw = 1;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d %d", &x[i], &y[i]);
	}
	for(int i=1; i<=N; i++){
		if(min(x[i], y[i]) >= draw){
			ans += min(x[i], y[i]) - draw + 1;
			draw = min(x[i], y[i]) + 1;
		}
		if(max(x[i], y[i]) > draw)draw = max(x[i], y[i]);
		if(x[i] == y[i] && x[i] == draw){
			draw++;
			ans++;
		}
	}
	printf("%d", ans);
}
