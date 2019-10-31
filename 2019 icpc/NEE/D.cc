#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stack>
 
std::pair<int, int> a[200001];
std::stack<std::pair<int, int> > temp;
std::vector<std::pair<int, std::pair<int, int> > > ans;
 
int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	std::sort(a, a+N);
	int prev = 1;
	for(int i=0; i<N; i++){
		if(i && a[i].first != a[i-1].first) prev = 1;
		else if(!temp.empty() && temp.top().first * temp.top().second == a[i].first){
			ans.push_back({a[i].second, temp.top()});
			temp.pop();
			continue;
		}
		for(; prev*prev<=a[i].first; prev++){
			if(a[i].first%prev) continue;
			ans.push_back({a[i].second, {prev, a[i].first/prev}});
			if(prev*prev!=a[i].first) temp.push({a[i].first/prev, prev});
			prev++;
			goto w;
		}
		goto v;
		w:;
	}
	std::sort(ans.begin(), ans.end());
	printf("YES\n");
	for(const auto &i:ans){
		printf("%d %d\n", i.second.first, i.second.second);
	}
	return 0;
	v:
	printf("NO\n");
	
}
