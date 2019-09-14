#include<stdio.h>
#include<algorithm>

using namespace std;

int N, M, now;
long long int a[100001], c[100001];
pair<int,int> cost[100001];

void serve(long long int i, long long int cnt){
	long long int ans = 0;
	if(a[i] > 0){
		if(a[i] >= cnt){
			ans += c[i] * cnt;
			a[i] -= cnt;
			printf("%lld\n", ans);
			return;
		}
		ans += c[i] * a[i];
		cnt -= a[i];
		a[i] = 0;
	}
	for(; cnt>0; now++){
		if(now>=N){
			printf("0\n");
			return;
		}
		if(a[cost[now].second] >= cnt){
			ans += cost[now].first * cnt;
			a[cost[now].second] -= cnt;
			printf("%lld\n", ans);
			return;
		}
		ans += cost[now].first * a[cost[now].second];
		cnt -= a[cost[now].second];
		a[cost[now].second] = 0;
	}
	printf("%lld\n", ans);
	return;
}

int main(void){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++) scanf("%lld", &a[i]);
	for(int i=0; i<N; i++) scanf("%lld", &c[i]);
	for(int i=0; i<N; i++){
		cost[i].first = c[i];
		cost[i].second = i;
	}
	sort(cost, cost+N);
	for(int i=0; i<M; i++){
		long long int x, y;
		scanf("%lld %lld", &x, &y);
		serve(x-1, y);
	}
}
