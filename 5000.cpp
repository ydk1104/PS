#include<stdio.h>
#define abs(x) (x)>0 ? (x) : -(x)

int main(void){
	int N;
	int di[2][100001];
	int sum = 0;
	scanf("%d", &N);
	for(int i=0; i<=1; i++)
		for(int j=1; j<=N; j++){
			int x;
			scanf("%d", &x);
			di[i][x] = j-x;
		}
		
	for(int j=1; j<=N; j++){
		sum += abs(di[1][j] - di[0][j]);
	}
	printf("%d", sum);
}
