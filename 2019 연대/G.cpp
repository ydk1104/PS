#include<stdio.h>

int ant[100001][2];
int circle[100001][100001];

int main(void){
	int N, M, Q;
	scanf("%d %d %d", &N, &M, &Q);
	for(int i=0; i<M; i++){
		int x, type;
		scanf("%d %d", &x, &type);
		ant[x%N][type]++;
	}
	
	for(;Q--;){
		int x, y;
		scanf("%d %d", &x, &y);
		int k = (y-1)/M;
		int t = k*N;
		y-=k*M;
		int left=0, right=N-1;
		while(left>right){
			int mid = (left+right)/2;
			if(mid==)
		}
		printf("%d\n", t-1);
	}
}
