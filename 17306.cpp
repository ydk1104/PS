#include<stdio.h>
#include<queue>

std::priority_queue<long long> pq;

int main(void){
	int N;
	scanf("%d", &N);
	long long x;
	for(int i=0; i<N; i++){
		scanf("%lld", &x);
		pq.push(x);
	}
	long long prev = -1;
	long long ans = 0;
	while(1){
		while(prev == pq.top()){
			pq.pop();
			if(pq.empty()) goto v;
		}
		prev = pq.top(); pq.pop();
		if(pq.empty()) break;
		ans++;
		pq.push(prev/2);
	}
	v:;
	printf("%d", ans);
}
