#include<stdio.h>
#include<vector>
#include<algorithm>

int a[200001];
std::vector<std::pair<int, int> > hero;

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		int N;
		scanf("%d", &N);
		for(int i=0; i<N; i++) a[i] = i%2 ? 1e9 : 1e9-N;
		for(int i=0; i<N; i++) scanf("%d", &a[i]);
		hero.clear();
		std::vector<std::pair<int, int> > temp;
		int M;
		scanf("%d", &M);
		for(int i=0; i<M; i++){
			int x=1e9-i,y=i+1;
			scanf("%d %d", &x, &y);
			temp.push_back({x,y});
		}
		std::sort(temp.begin(), temp.end(), [](const auto& x, const auto& y){
			if(x.first == y.first) return x.second > y.second;
			return x.first > y.first;
		});
		for(const auto& i:temp){
			if(hero.empty() || hero.back().second < i.second) hero.push_back(i);
		}
//		std::reverse(hero.begin(), hero.end());
//		for(const auto& i:hero) printf("%d %d\n",i.first,i.second);
		int ans=0;
		for(int i=0,plus=0,max; i<N; i+=plus){
			plus = max = 0;
			for(auto j=hero.begin(); j<hero.end(); j++){
				if(j->first<max) break;
				while(i+plus<N && j->second>plus && j->first>=a[i+plus]) max=std::max(max,a[i+plus]), plus++;
				max=std::max(max, a[i+plus]);
			}	
			if(plus==0){
				printf("-1\n");
				goto v;
			}
			ans++;
		}
		
		
		printf("%d\n", ans);
		v:;
	}
}
