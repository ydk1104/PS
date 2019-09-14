#include<stdio.h>

int value[11];

int main(void){
	int N, K;
	scanf("%d %d", &N, &K);
	for(int i=1; i<=N; i++){
		scanf("%d", &value[i]);
	}
	int ans = 0;
	while(K>0){
		if(K>=value[N]){
			ans += K/value[N];
			K %= value[N];
		}
		N--;
	}
	printf("%d", ans);
}
