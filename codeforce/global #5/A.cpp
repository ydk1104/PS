#include<stdio.h>

int main(void){
	int N, check=0;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x);
		int ans = (x+1)/2;
		if(x%2==0 && x<0) ans--;
		if(x%2 && check) ans--;
		printf("%d\n", ans);
		if(x%2){
			check ^= 1;
		}
	}
}
