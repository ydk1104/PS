#include<stdio.h>
#include<vector>
#include<queue>

std::vector<int> next[501];
int time[501], prev[501];

void input(int x){
	int y;
	scanf("%d", &y);
	time[x] = y;
	do{
		scanf("%d", &y);
		if(y==-1) return;
		prev[x]++;
		next[y].push_back(x);
	}while(1);
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++) input(i);
	std::priority_queue<std::pair<int, int> > pq;
	for(int i=1; i<=N; i++){
		if(!prev[i]) pq.push({-time[i], i});
	}
	while(!pq.empty()){
		auto now = pq.top(); pq.pop();
		int t = now.first, idx = now.second;
		for(const auto& i : next[idx]){
			prev[i]--;
			if(!prev[i]) pq.push({t-time[i], i});
		}
		time[idx] = -t;
	}
	for(int i=1; i<=N; i++) printf("%d\n", time[i]);
}
