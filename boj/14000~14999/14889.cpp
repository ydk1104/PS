#include<stdio.h>
#define min(a,b) ((a)>(b) ? (b) : (a))
#define abs(x) ((x)>0 ? (x) : (-(x)))
#define MAX 10000000

int stat[21][21];
int ans;

void back(int N, int now, int start[], int link[]){
	if(now==N+1){
		int s = 0, l = 0;
		for(int i=1; i<=start[0]; i++){
			for(int j=1; j<=start[0]; j++){
				s += stat[start[i]][start[j]];
			}
		}
		for(int i=1; i<=link[0]; i++){
			for(int j=1; j<=link[0]; j++){
				l += stat[link[i]][link[j]];
			}
		}
		ans = min(ans, abs(s-l));
		return;
	}
	start[++start[0]] = now;
	back(N, now+1, start, link);
	start[start[0]--] = 0;
	link[++link[0]] = now;
	back(N, now+1, start, link);
	link[link[0]--] = 0;
	return;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			scanf("%d", &stat[i][j]);
		}
	}
	int a[21] = {0, };
	int b[21] = {0, };
	ans = MAX;
	back(N, 1, a, b);
	printf("%d", ans);
}
