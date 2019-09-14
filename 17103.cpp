#include<stdio.h>
#define MAX 999999

int era[1000001];
int p[1000001];
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
	int T;
	scanf("%d", &T);
	while(T--){
		int N;
		scanf("%d", &N);
		if(N==4) printf("1");
		else{
			int ans = 0;
			for(int i=0; p[i]*2<=N; i++){
				if(!era[N-p[i]]) ans++;
			}
			printf("%d\n", ans);
		}
	}
}
