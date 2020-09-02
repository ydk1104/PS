#include<stdio.h>
#include<vector>
#include<algorithm>

std::pair<int, int> edge[200001];
std::vector<std::pair<int, int> > arr;
bool visited[200001];
int arrmin;

void dfs(int now, long long& sum, int& min, int& cnt){
	if(visited[edge[now].first]) return;
	visited[edge[now].first] = true;
	sum += edge[now].second;
	if(min > edge[now].second) min = edge[now].second;
	cnt++;
	dfs(edge[now].first, sum, min, cnt);
}

long long dfs(int start){
	if(visited[start]) return 0;
	long long sum=0;
	int min=1e8, cnt=0;
	dfs(start, sum, min, cnt);
	long long temp = (sum-min) + 1LL * (min) * (cnt-1);
	long long temp2 = (sum+min) + 1LL * (arr[0].first) * (cnt+1);
	if(temp > temp2) temp = temp2;
	return temp;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x);
		arr.push_back({x, i});
	}
	std::sort(arr.begin(), arr.end());
	for(int i=0; i<N; i++){
		edge[arr[i].second] = {i, arr[i].first};
	}
	long long ans = 0;
	for(int i=0; i<N; i++){
		ans += dfs(i);
	}
	printf("%lld", ans);
}
