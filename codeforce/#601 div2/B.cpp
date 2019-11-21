#include<stdio.h>
#include<algorithm>
#include<vector>

std::pair<int, int> a[1001];

int main(void){
	int T;
	for(scanf("%d", &T); T--;){
		int N, M;
		scanf("%d %d", &N, &M);
		for(int i=0; i<N; i++){
			scanf("%d", &a[i].first);
			a[i].second = i;
		}
		std::sort(a, a+N);
		std::vector<std::pair<int, int> > v;
		int sum=0;
		if(N==2) goto w;
		for(int i=0; i<N-1; i++){
			sum += a[i].first + a[i+1].first;
			v.push_back({a[i].second, a[i+1].second});
			M--;
		}
		sum += a[0].first + a[N-1].first;
		v.emplace_back(a[0].second, a[N-1].second);
		M--;
		if(M<0) goto w;
		while(M--) sum += a[0].first+a[1].first, v.emplace_back(a[0].second, a[1].second);
/*		if(N==3){
			if(M<3) goto v;
			else{
				sum += a[0].first+a[1].first;
				sum += a[1].first+a[2].first;
				sum += a[2].first+a[0].first;
				v.push_back({a[0].second, a[1].second});
				v.push_back({a[2].second, a[1].second});
				v.push_back({a[0].second, a[2].second});
				M -= 3;
				while(M--) v.push_back({a[0].second, a[1].second}), sum += a[0].first+a[1].first;
			}
		}
		else{
			if(M<(2*N-4)) goto v;
			else{
				for(int i=2; i<N; i++){
					sum += a[i].first + a[0].first;
					sum += a[i].first + a[1].first;
					v.push_back({a[0].second, a[i].second});
					v.push_back({a[1].second, a[i].second});
					M-=2;
				}
				while(M--){
					sum += a[0].first+a[1].first;
					v.push_back({a[0].second, a[1].second});
				}
			}
		}*/
		printf("%d\n", sum);
		for(const auto& i : v){
			printf("%d %d\n", i.first+1, i.second+1);
		}
		
		continue;
		w:;
		printf("-1\n");
	}
}
