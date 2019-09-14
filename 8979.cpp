#include<stdio.h>

int a[4][1001];
int ans=1;

int main(void){
	int N, M, K;
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++){
		for(int j=0; j<4; j++){
			scanf("%d", &a[j][i]);
		}
		if(a[0][i] == K) M=i;
	}
	for(int i=0; i<N; i++){
		for(int j=1; j<4; j++){
			if(a[j][i] > a[j][M]){
				ans++;
				break;
			}
			if(a[j][i] < a[j][M]) break;
		}
	}
	printf("%d",ans);
}
