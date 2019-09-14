#include<stdio.h>
#include<set>
#include<algorithm>
#include<vector>

std::vector<std::pair<std::pair<int, int>, int> > v;
std::multiset<std::pair<int, int> > s;
std::multiset<int>::iterator *p;

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x,y;
		scanf("%d %d", &x, &y);
		v.push_back({{x,y}, i+1});
	}
	sort(begin(v), end(v));
	int ans=0, cnt=0;
	for(auto &i : v){
		while(!s.empty() && i.first.first > (*s.begin()).first) s.erase(s.begin()), cnt--;
		s.insert({i.first.second, i.second});
		cnt++;
		if(cnt>ans){
			ans = cnt;
		}
	}
	printf("%d\n", ans);
	cnt = 0;
	s.clear();
	for(auto &i : v){
		while(!s.empty() && i.first.first > (*s.begin()).first) s.erase(s.begin()), cnt--;
		s.insert({i.first.second, i.second});
		cnt++;
		if(cnt==ans){
			for(auto &j : s) printf("%d ", j.second);
			return 0;
		}
	}
}
