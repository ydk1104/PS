#include<stdio.h>
#include<tuple>
#include<algorithm>

std::pair<long long, long long> time[200011];

int main(void){
	#define int long long
	int Test;
	for(scanf("%lld", &Test); Test--;){
		int N, T, S, L;
		scanf("%lld %lld %lld %lld", &N, &T, &S, &L);
		int cnt[2] = {0,};
		for(int i=0; i<N; i++) scanf("%lld", &time[i].second), cnt[time[i].second]++;
		for(int i=0; i<N; i++) scanf("%lld", &time[i].first);
		std::sort(time, time+N);
		time[N].first = T+1;
		int min = 0, ans = 0;
		int remainTime = time[0].first - 1, remainCnt = std::min(remainTime/S, cnt[0]);
			remainTime -= remainCnt * S;	remainCnt += std::min(remainTime/L, cnt[1]);
		ans = std::max(ans, remainCnt);
		for(int i=0; i<N; i++){
			min += time[i].second ? L : S;
			cnt[time[i].second]--;
			if(min >= time[i+1].first) continue;
			remainTime = time[i+1].first - min - 1;	remainCnt = std::min(remainTime/S, cnt[0]);
			remainTime -= remainCnt * S;			remainCnt += std::min(remainTime/L, cnt[1]);
			ans = std::max(ans, remainCnt + i + 1);
		}
		printf("%lld\n", ans);
	}
}
