#include<stdio.h>
#include<vector>

int win[200001], lose[200001], pa[200001], cnt[200001];

int find(int x){
	return pa[x] ? find(pa[x]) : x;	
}

void merge(int x, int y){
	x = find(x), y = find(y);
	if(x==y) return;
	if(win[x] > win[y]){pa[y] = x, cnt[x] += cnt[y]; return;}
	if(win[x] < win[y]){pa[x] = y, cnt[y] += cnt[x]; return;}
	if(lose[x] < lose[y]){pa[y] = x, cnt[x] += cnt[y]; return;}
	if(lose[x] > lose[y]){pa[x] = y, cnt[y] += cnt[x]; return;}
	if(x < y){pa[y] = x, cnt[x] += cnt[y]; return;}
	if(x > y){pa[x] = y, cnt[y] += cnt[x]; return;}
}

std::vector<std::pair<int, int> > v;

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++) cnt[i] = 1;
	for(int i=0; i<M; i++){
		int x,y;
		scanf("%d %d", &x, &y);
		win[x]++;
		lose[y]++;
		v.push_back({x,y});
	}
	for(auto i:v){
		merge(i.first, i.second);
	}
	int ans=0, anscnt=-1;
	for(int i=1; i<=N; i++){
		if(anscnt < cnt[i]){
			anscnt = cnt[i];
			ans = i;
		}
	}
	printf("%d", ans);
}
