#include<stdio.h>

typedef struct Queue{
	int check;
	int pri;
}Queue;

Queue Q[10001];
int start;
int end;
int cnt;
int CHECK;

int main(void){
	int T;
	scanf("%d", &T);
	for(; T>0; T--){
		int N, M;
		scanf("%d %d", &N, &M);
		start = cnt = 0;
		end = N;
		CHECK = 1;
		for(int i=0; i<N; i++){
			scanf("%d", &Q[i].pri);
			Q[i].check = 0;
		}
		Q[M].check = 1;
		while(CHECK){
			int Qmax = start;
			for(int i=start+1; i!=end; i++){
				if(i>10000) i = 0;
				if(Q[Qmax].pri<Q[i].pri) Qmax = i;
			}
			while(start!=Qmax){
				Q[end] = Q[start];
				end++;
				if(end>10000) end=0;
				start++;
				if(start>10000) start=0;
			}
			CHECK -= Q[start].check;
			start++;
			if(start>10000) start=0;
			cnt++;
		}
		printf("%d\n", cnt);
	}
}
