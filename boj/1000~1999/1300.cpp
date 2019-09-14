#include<stdio.h>
#include<algorithm>
#define MAX 93000000

using namespace std;

int Dcnt[MAX+1]; // divisor count

void test(int N){
	int a[1001], cnt=0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			printf("%d ", i*j);
			a[cnt++] = i*j;
		}
		printf("\n");
	}
	sort(a, a+cnt);
//	for(int i=0; i<cnt; i++) printf("%d ", a[i]);
}

int count(int x, int max){
	int cnt = 0;
	for(int i=1; i*i<=x && i<=max; i++){
		if(x%i == 0 && x/i<=max) cnt+=2;
		if(i*i == x) cnt--;
	}
	return cnt;
}

int main(void){
	int N, K, cnt=0, i=1;
	scanf("%d\n%d", &N, &K);
	test(N);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N && i*j<=MAX; j++){
			Dcnt[i*j]++;
		}
	}
	for(; cnt<K && i<MAX; i++){
		cnt += Dcnt[i];
	}
	printf("%d %d", i-1, cnt);
}
