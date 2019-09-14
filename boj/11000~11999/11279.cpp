#include<stdio.h>
#include<queue>

std::priority_queue<int> pq;

int main(void){
	int N;
	scanf("%d", &N);
	while(N--){
		int x;
		scanf("%d", &x);
		if(x) pq.push(x);
		else{
			if(pq.empty()) printf("0\n");
			else printf("%d\n", pq.top()), pq.pop();
		}
	}
}
