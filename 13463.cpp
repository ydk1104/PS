#include <bits/stdc++.h>
using namespace std;
 
queue<int> q;
vector<int> v[200001];
int cnt[200001];
int cntL[200001];
int visit[200001];
int C,P,X,L, x, y, now;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	/* code */
	cin >> C >> P >> X >> L;
	for(int i=0; i<P; i++){
		cin >> x >> y;
		cnt[x]++; cnt[y]++;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	q.push(L);
	visit[L] = 1;
	while(!q.empty()){
		now = q.front(); q.pop();
		if(now == X){
			cout << "leave";
			return 0;
		}
		for(auto &i : v[now]){
			cntL[i]++;
			if(cntL[i]*2>=cnt[i] && visit[i]==0){
				q.push(i);
				visit[i] = 1;
			}
		}
	}
	cout << "stay";
	return 0;
}
