#include<stdio.h>
#include<vector>

using namespace std;

vector<int> to[32001];
int can[32001];

struct Q{
	int queue[99999];
	int start, end;
	void push(int i){
		queue[end++] = i;
	}
	int pop(){
		return queue[start++];
	}
	int empty(){
		return start==end;
	}
}q;

int main(void){
	int N, M;
	for(scanf("%d %d", &N, &M);M--;){
		int x, y;
		scanf("%d %d", &x, &y);
		to[x].push_back(y);
		can[y]++;
	}
	for(int i=1; i<=N; i++){
		if(!can[i]) q.push(i);
	}
	while(!q.empty()){
		int now = q.pop();
		printf("%d ",now);
		for(auto i : to[now]){
			can[i]--;
			if(!can[i]) q.push(i);
		}
	}
}
