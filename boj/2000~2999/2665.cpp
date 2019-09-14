#include<stdio.h>
#include<queue>
#include<algorithm>

using namespace std;

char map[52][52];
int ans[52][52];

priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > >pq;

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%s", map[i]+1);
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			map[i][j]++;
	pq.push(make_pair(0, make_pair(1, 1)));
	int dx[4]={1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
	while(!pq.empty()){
		pair<int, pair<int, int> > now=pq.top(); pq.pop();
		while(!pq.empty() && ans[now.second.first][now.second.second]) now=pq.top(), pq.pop();
//		printf("%d %d %d %d\n", now.first, now.second.first, now.second.second, map[now.second.first][now.second.second]);
		ans[now.second.first][now.second.second] = now.first+1;
		for(int i=0; i<4; i++){
			int nowx = now.second.first+dx[i], nowy = now.second.second+dy[i];
			if(!map[nowx][nowy] || ans[nowx][nowy]) continue;
			pq.push(make_pair(now.first+2-map[nowx][nowy]+'0', make_pair(nowx, nowy)));
		}
	}
	printf("%d", ans[N][N]-1);
}
