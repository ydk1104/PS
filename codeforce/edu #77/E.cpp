#include<stdio.h>
#include<vector>
#include<tuple>
#include<algorithm>

int a[300001];
int fr;

int main(void){
	int N;
	scanf("%d", &N);
	int lgN = 1;
	while(1<<lgN != N) lgN++;
	for(int i=0; i<N; i++){
		scanf("%d", &a[i]);
		if(a[i]==-1) fr = i;
	}
	if(fr>=lgN){
		int ans = a[N-1];
		if(!~ans) ans=0;
		printf("%d", ans);
	}
	else{
//		std::sort(a+fr+1, a+N);
		std::vector<std::pair<int, int> > v;
		for(int i=fr+1; i<N; i++) v.push_back({i, a[i]});
		int To = lgN-fr;
		long long ans = a[N-1];
		for(int i=1; i<To; i++){
			int cnt=0;
			int now = fr+1;
			while(cnt < i) cnt += !!v[now++].first;
			auto min = std::min_element(v.begin()+now, v.end());
			min->first = 0;
			ans += min->second;
		}
		printf("%lld", ans);
	}
}
