#include<stdio.h>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<algorithm>

using namespace std;

set<int> s;
vector<pair<int, int> > v;
vector<int> edge[300010];
int visited[300010];

int dfs(int now){
	if(visited[now]) return 0;
	visited[now]++;
//	printf("%d\n", now);
	stack<int> temp;
	temp.push(now);
	while(!temp.empty()){
		int x = temp.top(); temp.pop();
//		printf("%d\n", x);
		for(auto i:edge[x]){
			if(!visited[i]) temp.push(i), visited[i]++;
		}
	}
	return 1;
}

int main(void){
	int N=300000;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		int x=i, r=1;
		scanf("%d %d", &x, &r);
		s.insert(x-r);
		s.insert(x+r);
		v.push_back(make_pair(x-r, x+r));
	}
	map<int, int> m;
	int cnt=0;
	for(auto i:s){
		m[i] = ++cnt;
	}
	for(auto i:v){
//		printf("%d %d\n",m[i.first], m[i.second]);
		edge[m[i.first]].push_back(m[i.second]);
		edge[m[i.second]].push_back(m[i.first]);
	}
	int ans = 0;
	for(int i=1; i<=cnt; i++) ans += dfs(i);
	printf("%d", ans+1-cnt+2*N);
}
