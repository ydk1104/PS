#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class node{
	public:
	int visited;
	vector<int> v;
};

node v[1001];

void clean(int N){
	printf("\n");
	for(int i=1; i<=N; i++) v[i].visited = 0;
}

void DFS(int now){
	if(v[now].visited) return;
	printf("%d ", now);
	v[now].visited = 1;
	vector<int>::iterator p;
	for(p = v[now].v.begin(); p!=v[now].v.end(); p++) DFS(*p);
}

void BFS(int now){
	queue<int> Q;
	Q.push(now);
	v[now].visited = 1;
	while(Q.empty() != 1){
		int temp = Q.front();
		printf("%d ", temp);
		vector<int>::iterator p;
		vector<int> t;
		for(p=v[temp].v.begin(); p!=v[temp].v.end(); p++){
			if(!v[*p].visited){
				v[*p].visited = 1;
				t.push_back(*p);
			}
		}
		sort(t.begin(), t.end());
		for(p=t.begin(); p!=t.end(); p++){
			Q.push(*p);
		}
		Q.pop();
	}
}

int main(void){
	int N, M, V;
	scanf("%d %d %d", &N, &M, &V);
	for(int i=0; i<M; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].v.push_back(y);
		v[y].v.push_back(x);
	}
	for(int i=0; i<N; i++) sort(v[i].v.begin(), v[i].v.end());
	DFS(V);
	clean(N);
	BFS(V);
}
