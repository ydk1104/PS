#include<stdio.h>
#include<queue>
#include<vector>
#include<functional>
#include<algorithm>

std::pair<int, int> a[200001];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d %d", &a[i].first, &a[i].second);
	std::sort(a, a+N);
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	pq.push(0);
	for(int i=0; i<N; i++){
		pq.push(a[i].second);
		if(pq.top() <= a[i].first) pq.pop();
	}
	printf("%d", pq.size());
}
