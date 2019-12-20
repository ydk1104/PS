#include<stdio.h>
#include<queue>

int main(void){
/*	
	std::queue<std::pair<int, int> > q;
	q.push({0, 0});
	int arr[10010] = {0, };
	int* parr = arr+5050;
	while(!q.empty()){
		auto now = q.front(); q.pop();
		if(now.second == 7) return 0;
		if(now.first > 0 && !parr[now.first]) printf("%d %d\n", now.first, now.second);
		parr[now.first] = 1;
		q.push({now.first-now.second-1, now.second+1});
		q.push({now.first+now.second+1, now.second+1});
	}
// */	
	
	int N;
	scanf("%d", &N);
	while(N--){
		int a,b;
		scanf("%d %d", &a, &b);
		int minus = a-b;
		if(minus<0) minus=-minus;
		int i=0, sum=0;
		for(; sum<minus || sum%2 != minus%2;) sum += ++i;
		printf("%d\n",i);
		
	}
}
/* 
0 1 3 6 10 15
0 -> 0
1 -> 1
2 -> 3
3 -> 2
4 -> 3
5 -> 5
6 -> 3
7 -> 5
8 -> 4
9 -> 5
10 -> 4
*/
