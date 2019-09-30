#include<stdio.h>
#include<vector>
#include<algorithm>

std::vector<int> v[200001];

int arr[100001];
int t[200001];
int cnt[200001];
int plus[2];

void dfs(int now, int type){
	if(v[now].size()==0){
		plus[type]++;
		return;
	}
	dfs(v[now][0], type);
	dfs(v[now][1], type ^ t[now]);
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &arr[i]);
	}
	std::sort(arr, arr+N);
	for(int i=0; i<N-1; i++){
		char type;
		int x,y;
		scanf("%*c%c %d %d", &type, &x, &y);
		x--; y--;
		v[i+N].push_back(x); v[i+N].push_back(y);
		t[i+N] = type == '-';
		cnt[x]++; cnt[y]++;
	}
	for(int i=0; i<N-1; i++){
		if(cnt[i+N]) continue;
		dfs(i+N, 1);
	}
	long long ans = 0;
	for(int i=0; i<N; i++){
		if(i<plus[0]) ans -= arr[i];
		else ans += arr[i];
	}
	printf("%d", ans);
}
