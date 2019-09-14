#include <bits/stdc++.h>
using namespace std;

struct P{
	int s;
	int e;
};

#define MAX 1000

vector<int> adj[MAX+1];
P node[MAX+1];
int indegree[MAX+1];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, Q;
	cin >> N >> M >> Q;
	for (int i = 0 ; i < M; i++)  {
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
		indegree[a]++;
	}

	for (int i = 1; i <= N; i++) {
	 	node[i].s = node[i].e = i;
	}

	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if(indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int next : adj[now]) {
			node[next].s = min(node[next].s, node[now].s);
			node[next].e = max(node[next].e, node[now].e);
			if(--indegree[next] == 0) {
				q.push(next);
			}
		}
	}

	while(Q--) {
		int w, x, y;
		cin >> w >> x >> y;
		if (w == 1) {
			int s = MAX+1;
			int e = -1;
			for (int i =x ; i <=y; i++) {
				s = min(s, node[i].s);
				e = max(e, node[i].e);
			}
			//cout<< s << ' ' << e << '\n';
			if(x <= s && e <= y) {
				cout << "YES\n";
			} 
			else cout << "NO\n";
		}
	}
	return 0;
}
