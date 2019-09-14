#include<stdio.h>
#define min(a,b) ((a)>(b) ? (b) : (a))
#define max(a,b) ((a)<(b) ? (b) : (a))

int unitmin, unitmax, ans;
int shield[501];
int unit[501];

int main(void){
	ans = unitmin = 1000000000;
	int M, N, K;
	scanf("%d %d %d", &M, &N, &K);
	for(int i=1; i<=M; i++){
		scanf("%d", &shield[i]);
	}
	for(int i=1; i<=N; i++){
		scanf("%d", &unit[i]);
		unitmin = min(unitmin, unit[i]);
		unitmax = max(unitmax, unit[i]);
	}
	if(K==1){
		for(int i=1; i<=M; i++){
			ans = min(ans, max(unitmax-shield[i], shield[i]-unitmin));
		}
	}
	printf("%d", ans);
}
