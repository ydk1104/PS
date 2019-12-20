#include<stdio.h>
#include<vector>
#include<algorithm>

std::vector<int> edge[1000001];
int visited[1000001];

struct segeTree{
	static const int N = 2.2e6;
	int max = 524288*2;
	std::vector<int> arr[N];
	void update(int x, int value){
		x = x+max-1;
		arr[x].push_back(value);
		while(x/=2){
			arr[x].push_back(value);
		}
	}
	int sum(int l, int r){
		return sum(l,r,1,max,1);
	}
	int sum(int l, int r, int nl, int nr, int now){
		if(r < nl || l > nr) return 0;
		if(l <= nl && nr <= r){
			for(const auto& i : arr[now]) edge[r].push_back(i), edge[i].push_back(r);
			return arr[now].size();
		}
		int mid = (nl+nr)/2;
		return sum(l,r,nl,mid,now*2) + sum(l,r,mid+1,nr,now*2+1);
	}

}ST;

int dfs(int now){
	int temp = 1;
	for(const auto& i : edge[now]){
		if(!visited[i]) temp += dfs(visited[i]=i);
	}
	return temp;
}

int main(void){
	int N;
	scanf("%d", &N);
	std::vector<std::pair<int, int> > v, iter;
	for(int i=0; i<N; i++){
		int x,y;
		scanf("%d %d", &x, &y);
		v.emplace_back(x,y);
	}
	std::sort(v.begin(), v.end());
	int max = v[0].second;
	int edge = 0;
	for(const auto& i : v){
		edge += ST.sum(i.first, i.second);
		ST.update(i.second, i.second);
		if(edge >= N) break;
	}
	if(edge != N-1){
		printf("NO");
		return 0;
	}
	visited[v[0].second] = true;
	int component = dfs(v[0].second);
	printf("%s\n", component==N?"YES":"NO");
}
