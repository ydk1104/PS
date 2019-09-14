#include<stdio.h>
#define MAX 99999

int era[1000001];
int p[10001];
int cnt;
int ans[1000001];

int main(void){
	for(int i=3; i<MAX; i+=2){
		if(era[i]) continue;
		for(int j=3; i*j<MAX; j+=2){
			era[i*j]++;
		}
		p[cnt++]=i;
	}
	printf("%d",cnt);
	for(int i=1; i<cnt; i++){
		for(int j=i; p[i]+p[j]<=MAX; j++){
			ans[p[i]+p[j]]++;
		}
	}
	int T=0;
//	scanf("%d", &T);
	while(T--){
		int N;
		scanf("%d", &N);
		printf("%d\n", ans[N]);
	}
}
