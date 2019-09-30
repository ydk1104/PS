#include<stdio.h>
#include<vector>
#include<algorithm>

std::vector<std::pair<int, long long> > v;

int go(long long now, long long N, long long M, long long K){
	long long sum = 0, cnt = 0;
	for(int i=0; cnt<N && i<K; i++){
		if(v[i].second <= now){
			sum += v[i].first;
			cnt++;
		}
	}
//	printf("%d %d %d\n", now, sum, M);
	return sum >= M && cnt == N;
}

int main(void){
	long long N, M, K;
	scanf("%d %lld %d", &N, &M, &K);
	for(int i=0; i<K; i++){
		long long x,y;
		scanf("%d %lld", &x, &y);
		v.push_back({x,y});
	}
	std::sort(v.begin(), v.end(), [](std::pair<int, long long> x, std::pair<int, long long> y){
		return x.first > y.first;
	});
	long long left=0, right=3e9;
	while(left<right){
//		printf("%lld %lld\n", left, right);
		long long mid = (left+right)/2;
		if(!go(mid, N, M, K)) left=mid+1;
		else right=mid-1;
	}
	for(long long i=left-2; i<=left+2; i++){
		if(go(i, N, M, K)){
			printf("%lld", i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}
