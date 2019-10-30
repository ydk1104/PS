#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>

bool go(std::vector<std::pair<int, int> >& v, int N, long long P, int mid){
	long long mid_index = (N+1)/2;
	if(P < mid_index*mid) return 0;
	std::priority_queue<int> pq;
	long long sum = 0;
	for(int i=0; i<N; i++){
		if(i<mid_index && v[i].second<mid) return 0;
		if(v[i].second >= mid) pq.push(std::max(v[i].first, mid)-v[i].first), sum += std::max(v[i].first, mid);
		else sum += v[i].first;
	}
	while(sum > P && !pq.empty()){
		int temp = pq.top(); pq.pop();
		sum -= temp;
		if(pq.size() < mid_index) return 0;
	}
	return 1;
}

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		int N; long long P;
		std::vector<std::pair<int, int> > v;
		scanf("%d %lld", &N, &P);
		for(int i=0; i<N; i++){
			int x,y;
			scanf("%d %d", &x, &y);
			v.push_back({x,y});
//			w.push_back({x,y});
		}
		std::sort(v.begin(), v.end(), [](std::pair<int, int>& x, std::pair<int, int>& y){
			return x.second > y.second;
		});
//		printf("test : ");
//		for(auto i:v) printf("%d %d\n",i.first, i.second);
//		printf("\nend test");
		int left=0, right=1e9+10;
		while(left<right-1){
			int mid = (left+right)/2;
			if(go(v, N, P, mid)) left = mid;
			else right = mid-1;
		}
		for(int i=left-1; i<=right+1; i++){
			if(!go(v,N,P,i)){
				printf("%d\n", i-1);
				break;
			}
		}
	}
}
