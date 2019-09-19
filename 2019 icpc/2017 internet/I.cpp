#include<stdio.h>
#include<algorithm>

int map[1001][1001];
long long sum, sum2;
int *maxi[1001], *maxj[1001];

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			scanf("%d", &map[i][j]);
			if(!maxi[i] || *maxi[i] < map[i][j]) maxi[i] = &map[i][j];
			if(!maxj[j] || *maxj[j] < map[i][j]) maxj[j] = &map[i][j];
//			map[i][0] = std::max(map[i][0], map[i][j]);
//			map[0][j] = std::max(map[0][j], map[i][j]);
			sum += map[i][j];
		}
	}
	for(int i=1; i<=N; i++){
		sum2 += *maxi[i];
		*maxi[i] = 0;
	}
	for(int j=1; j<=M; j++){
		sum2 += *maxj[j];
	}
	printf("%lld", sum-sum2);
}
