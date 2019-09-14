#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
ll N, M, X, MAX, x, y, t;
bool visit[10001]; 
ll cost[10001];
vector<pair<ll, int> > v[10001];
 
bool go(ll mid) {
	for(int i=1; i<=N; i++) cost[i] = LONG_LONG_MIN;
	for(int i=1; i<=N; i++) visit[i] = 0;
	priority_queue<pair<ll, int> > pq;
 
	pq.push({0, 1});
	while(!pq.empty()){
		auto now = pq.top(); pq.pop();
		if(now.second == N){
			if(-now.first <= MAX) {
				return true;
			}
			break;
		}
		if(visit[now.second]) continue;
		visit[now.second] = true;
		for(auto &i : v[now.second]){
			if(visit[i.second]) continue;
			if(i.first > mid) continue;
			if(cost[i.second] < now.first-i.first){
				cost[i.second] = now.first - i.first;
				pq.push({cost[i.second], i.second});
			}
		}
	}
	return false;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M >> X;
 
	for(int i=0; i<M; i++){
		cin >> x >> y >> t;
		v[x].push_back({t, y});
		v[y].push_back({t, x});
	}
 
	for(int i=1; i<=N; i++) cost[i] = LONG_LONG_MIN;
 
	priority_queue<pair<ll, int> > pq;
	pq.push({0, 1});
	while(!pq.empty()){
		auto now = pq.top(); pq.pop();
		if(now.second == N){
			MAX = -now.first * (100 + X) / 100;
 
			break;
		}
		if(visit[now.second]) continue;
		visit[now.second] = 1;
		for(auto &i : v[now.second]){
			if(visit[i.second]) continue;
			if(cost[i.second] < now.first-i.first){
				cost[i.second] = now.first - i.first;
				pq.push({cost[i.second], i.second});
			}
		}
	}
 
	ll left=0, right=1e10;
	while(left<right){
		ll mid = (left+right)/2ll;
		if (!go(mid)) {
			left = mid + 1ll;
		} else {
			right = mid;
		}
	}
	cout << left;
	return 0;
}
