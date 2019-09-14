#include<stdio.h>

int main(void){
	int N;
	int w[51], h[51], ans[51] = {0, };
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d %d", &w[i], &h[i]);
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(w[i]<w[j] && h[i]<h[j]){
				ans[i] ++;
			}
		}
		printf("%d ", ans[i]+1);
	}
}
