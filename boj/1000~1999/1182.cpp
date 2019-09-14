#include<stdio.h>

int N, S;
int num[20];

int find(int pr, int sum, int count){
	int cnt = 0;
	if(sum == S && count>0) cnt++;
	if(pr == N) return cnt;
	cnt += find(pr+1, sum+num[pr+1], count+1) + find(pr+1, sum, count);
	return cnt;
}

int main(void){
	scanf("%d %d", &N, &S);
	for(int i=0; i<N; i++){
		scanf("%d", &num[i]);
	}
	int ans = find(-1, 0, 0);
	printf("%d", ans);
}
