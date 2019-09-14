#include<stdio.h>
#define max(a,b) (a)>(b) ? (a) : (b)

int day[100001];
int N, M, K;
int sum;
int ans;

void BS(int left, int right){
	if(left > right) return;
	K = (left+right)/2;
	int temp = K;
	int cnt = 1;
	for(int i=1; i<=N; i++){
		if(temp>=day[i]) temp -= day[i];
		else temp = K-day[i], cnt++;
	}
	if(cnt<=M){
		ans = K;
		return BS(left, K-1);
	}
	return BS(K+1, right);
}

int main(void){
	scanf("%d %d", &N, &M);
	int daymax = 0;
	for(int i=1; i<=N; i++){
		scanf("%d", &day[i]);
		daymax = max(daymax, day[i]);
		sum += day[i];
	}
	BS(daymax, sum);
	printf("%d", ans);
}
