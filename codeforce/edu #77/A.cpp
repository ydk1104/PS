#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x,y;
		scanf("%d %d", &x, &y);
		int ans = 0;
		for(int j=0; j<x; j++){
			int now= (y/x)+((y%x)>j);
			ans += now*now;
		}
		printf("%d\n", ans);
	}
}
