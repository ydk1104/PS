#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	int ans = 0;
	for(int i=1; i<=N; i++){
		int x;
		scanf("%d", &x);
		ans += x-1;
	}
	printf("%d", ans+1);
}
