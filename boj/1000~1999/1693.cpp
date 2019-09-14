#include<stdio.h>
#include<vector>
#define min(a,b) ((a)>(b)?(b):(a))
#define MAX 1000000000
#define color 20

std::vector<int> v[100001];
std::vector<int> T[100001];
int check[100001][color+1];

int make_tree(int now){
	if(check[now][0]) return 0;
	check[now][0]++;
	for(std::vector<int>::iterator p=v[now].begin(); p!=v[now].end(); p++){
		if(make_tree(*p)) T[now].push_back(*p);
	}
	return 1;
}

int dfs(int now, int cost){
	if(cost>color || cost<1) return MAX;
	if(check[now][cost]) return check[now][cost];
	check[now][cost] = cost;
	for(std::vector<int>::iterator p=T[now].begin(); p!=T[now].end(); p++){
		int t = MAX;
		for(int i=1; i<=color; i++){
			if(i==cost) continue;
			t = min(t, dfs(*p, i));
		}
		check[now][cost] += t;
	}
//	printf("%d %d %d\n", now, cost, check[now][cost]);
	return check[now][cost];
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<N; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	make_tree(1);
	int ans = MAX;
	for(int i=1; i<=color; i++){
		ans = min(ans, dfs(1, i));
	}
	printf("%d", ans);
}

