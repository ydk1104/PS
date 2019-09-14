#include<stdio.h>

int map[101], sec[101], start[101];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%1d", &map[i]);
	for(int i=0; i<N; i++){
		scanf("%d %d", &sec[i], &start[i]);
	}
	int ans=0;
	for(int t=0; t<=250; t++){
		int nowOn = 0;
		for(int i=0; i<N; i++) nowOn += map[i];
		if(ans<nowOn) ans=nowOn;
		for(int i=0; i<N; i++){
			if(t>=start[i] && (t-start[i])%sec[i]==0){
				map[i]=1-map[i];
			}
		}
	}
	printf("%d",ans);
}
