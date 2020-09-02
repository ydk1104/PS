#include<stdio.h>
#include<vector>

bool visited[200001];
std::vector<int> v[200001];

int dfs(int now){
	if(!v[now].size()) return -1;
	int temp = v[now].size()%2;
	for(const auto& i : v[now]){
		if(!visited[i]){
			visited[i] = true;
			temp += dfs(i);
		}
	}
	return temp;
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	while(M--){
		int x,y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int ans = 0;
	for(int i=1; i<=N; i++){
		if(!visited[i]){
			visited[i] = true;
			int temp = dfs(i);
			if(!temp) temp = 2;
			ans += temp/2;
		}
	}
	printf("%d", ans);
}
