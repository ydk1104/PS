#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	int ans=0;
	for(int i=0; i<=N; i++){
		for(int j=0; j<=i; j++){
			ans += i+j;
		}
	}
	printf("%d", ans);
}
