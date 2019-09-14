#include<stdio.h>
#include<algorithm>
#include<queue>

using namespace std;

vector<vector<int> > v(2001, vector<int>(0));
int enemy[2001][2001];

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x); 
	}
	for(int i=1; i<=N; i++){
		int check[2001] = {0, };
		queue<int> q;
		q.push(i);
		int roop = 1;
		while(!q.empty()){
			int now = q.front(); q.pop();
			printf("now=%d\n", now);
			for(vector<int>::iterator p=v[now].begin(); p!=v[now].end(); p++){
				if(check[*p]) continue;
				check[*p] = 1;
				printf("%d %d %d %d %d\n", now, *p, roop, v[now][*p], v[*p][now]);
				if(!v[now][*p]) v[now][*p] = roop, q.push(*p);
				else if(v[now][*p]%2 != roop%2) goto v;
//				if(!v[*p][now]) v[*p][now] = roop, q.push(*p);
//				else if(v[*p][now]%2 != roop%2) goto v;
			}
			roop++;
		}
	}
	printf("1");
	return 0;
	v:
		printf("0");
}
