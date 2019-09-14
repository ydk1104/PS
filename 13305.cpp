#include<stdio.h>
#define min(a,b) (a>b) ? (b) : (a)

long long int map[100001];
long long int oil[100001];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<N; i++){
		scanf("%lld", &map[i]);
	}
	for(int i=1; i<=N; i++){
		scanf("%lld", &oil[i]);
	}
	long long int oilmin = oil[1];
	long long int ans = 0;
	for(int i=1; i<N; i++){
		oilmin = min(oilmin, oil[i]);
		ans += map[i] * oilmin;
	}
	printf("%lld", ans);
}
