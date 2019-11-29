#include<stdio.h>
#include<vector>
#include<tuple>
#include<algorithm>

int N, max, K, T;
int a[200001];
int cost[200001];
std::vector<std::pair<int, int> > v, v2;

std::vector<std::pair<int, std::pair<int, int> > > V;

const int NMAX = 1<<18;

struct segeTree{
	int MAX = NMAX; // n <= 10^6
	long long value[NMAX<<1];
	long long lazy[NMAX<<2];
	void __init__(int N){
		for(int i=MAX-1; i; i--) value[i] = 0;
	}
	void p(int now, int cnt){
		if(!lazy[now]) return;
		value[now] = cnt;
		lazy[now*2] = true;
		lazy[now*2+1] = true;
	}
	void update(int l, int r, long long x){return update(l, r, 1, MAX, 1, x);}
	void update(int l, int r, int nl, int nr, int now, long long x){
		p(now, nr-nl+1);
		if(l > nr || r < nl) return;
		if(l <= nl && nr <= r){
			lazy[now] = true;
			p(now, nr-nl+1);
			return;
		}
		int mid = (nl+nr)/2;
		update(l, r, nl, mid, now*2, x); update(l, r, mid+1, nr, now*2+1, x);
		value[now] = value[now*2] + value[now*2+1];
	}
	long long sum(int l, int r){return sum(l, r, 1, MAX, 1);};
	long long sum(int l, int r, int nl, int nr, int now){
		if(l > nr || r < nl) return 0;
		p(now, nr-nl+1);
		if(l <= nl && nr <= r) return value[now];
		int mid = (nl+nr)/2;
		return sum(l, r, nl, mid, now*2) + sum(l, r, mid+1, nr, now*2+1);
	}
}ST;

void prev(){
	for(int i=0; i<K; ){
		int now=i;
		while(now<K && V[now].first == V[i].first){
			ST.update(V[now].second.first, V[now].second.second, 1);
			now++;
		}
		cost[V[i].first-1] = ST.sum(1, max)*2;
		i = now;
	}
	for(int i=200000; i; i--) cost[i-1] = std::max(cost[i-1], cost[i]);
}

bool go_ver1(int now){
	if(now<=0) return 1;
	if(now>N) return 0;
	int min = a[now-1], temp = 0;
	int visited[200001] = {0, };
	for(int i=0; i<K; i++){
		if(min < v[i].first) temp += v[i].second*2-visited[v2[i].first], visited[v2[i].second]=1;
		if(temp > T) return 0;
	}
	return 1;
}
/*
bool go(int now){
	if(now<=0) return 1;
	if(now>N) return 0;
	int min = a[now-1], temp = 0;
	int visited[200001] = {0, };
	for(const auto& i : V){
		if(min < i.second){
			temp += (i.first.second - i.first.first + 1 - visited[i.first.first]) * 2;
			visited[i.first.second] = 1;
		}
		if(temp>T) return 0;
	}
//	printf("%d %d\n", now, temp+max+1);
	return 1;
} // */

bool go(int now){
	if(now<=0) return 1;
	if(now>N) return 0;
	int min = a[now-1];
//	printf("%d %d %d\n",now, min, cost[min]);
	return cost[min] <= T;
}

int main(void){
	scanf("%d %d %d %d", &N, &max, &K, &T);
	T -= max+1;
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	std::sort(a, a+N, [](int &x, int &y){
		return x>y;
	});
	for(int i=0; i<K; i++){
		int x,y,z;
		scanf("%d %d %d", &x, &y, &z);
		v.push_back({z,y-x+1});
		v2.push_back({x,y});
		V.push_back({z, {x,y}});
	}
	std::sort(V.begin(), V.end(), [](const auto& x, const auto& y){
		return x.first > y.first;
	});
	prev();
	int l=0, r=N;
//	for(int i=l; i<=r; i++) go(i);
	while(l<r){
		int mid = l+r>>1;
		if(go(mid)) l=mid+1;
		else r=mid-1;
	}
	for(int mid=l-1; ; mid++){
		if(!go(mid)){
			printf("%d", mid-1);
			break;
		}
	}
}
