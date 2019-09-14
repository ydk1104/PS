#include<stdio.h>
#include<vector>
#include<algorithm>

std::vector<std::pair<int, int> > v;

int main(void){
	int N, e;
	scanf("%d %d", &N, &e);
	for(int i=0; i<N; i++){
		int x,y;
		scanf("%d %d", &x, &y);
		v.emplace_back(x,y);
	}
	std::sort(begin(v), end(v));
	int ans=0;
	for(int i=0; i<N;){
		int min=v[i].second, max=v[i].second, j=i;
		while(max-min <= e*2 && j<N){
			j++;
			max = std::max(v[j].second, max);
			min = std::min(v[j].second, min);
		}
		i=j;
		ans++;
	}
	printf("%d", ans);
}
