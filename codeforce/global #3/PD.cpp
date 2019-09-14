#include<stdio.h>
#include<vector>
#include<tuple>
#include<algorithm>

using namespace std;

vector<pair<int, int> > v[2];

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.second > b.second;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x,y;
		scanf("%d %d", &x, &y);
		if(x<y) v[0].push_back({i+1,y});
		else v[1].push_back({i+1,-y});
	}
	sort(v[0].begin(), v[0].end(),cmp);
	sort(v[1].begin(), v[1].end(),cmp);
	if(v[0].size()>v[1].size()) {printf("%d\n", v[0].size());for(auto i:v[0]) printf("%d ",i.first);}
	else {printf("%d\n", v[1].size());for(auto i:v[1]) printf("%d ",i.first);}
	
}
