#include<stdio.h>

int main(void){
	int N, K;
	int cnt = 0;
	scanf("%d %d", &N, &K);
	int era[100001] = {0, };
	for(int i=2; i<=N; i++){
		for(int j=1; i*j<=N; j++){
			if(!era[i*j]){
				era[i*j] = 1;
				cnt++;
				if(cnt == K){
					printf("%d", i*j);
					return 0;
				}
			}
		}
	}
}
