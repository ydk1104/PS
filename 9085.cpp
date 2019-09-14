#include<stdio.h>

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		int N;
		scanf("%d", &N);
		int sum=0;
		while(N--){
			int x;
			scanf("%d", &x);
			sum+=x;
		}
		printf("%d\n", sum);
	}
}
