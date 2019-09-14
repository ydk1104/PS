#include<stdio.h>

int sum[1001];

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	int nowNum = 1;
	int now = 0;
	for(int i=1; i<=M; i++){
		sum[i] = sum[i-1]+nowNum;
		now++;
		if(nowNum==now) nowNum++, now=0;
	}
	printf("%d", sum[M]-sum[N-1]);
}
