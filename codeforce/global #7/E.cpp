#include<stdio.h>
#include<queue>

int a[300001];
int b[300001];
std::priority_queue<std::pair<int, int> > pq1, pq2;

int main(void){
	int N;
	scanf("%d", &N);
	
	for(int i=0; i<N; i++){
		scanf("%d", a+i);
		pq1.push({a[i], i+1});
	}
	for(int i=0; i<N-1; i++){
		scanf("%d", b+i);
//		pq2.push_back(i, b[i]);
	}
	int max = N;
	std::priority_queue<int> pq;
	for(int i=0; i<N; i++){
		printf("%d ", pq1.top().first);
		if( b[i] >= pq1.top().second ){
			pq1.pop();
		}
		else{
			pq.push(-b[i]);
		}
		while(pq.size() && (pq.top() >= pq1.top().second)){
			pq.pop(); pq1.pop();
		}
	}
}
