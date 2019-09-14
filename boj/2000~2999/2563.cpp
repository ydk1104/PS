#include<stdio.h>

int map[120][120];

int main(void){
	int N;
	scanf("%d", &N);
	while(N--){
		int x, y;
		scanf("%d %d", &x, &y);
		for(int i=0; i<10; i++){
			for(int j=0; j<10; j++){
				map[x+i][y+j]=1;
			}
		}
	}
	int ans=0;
	for(int i=0; i<=100; i++){
		for(int j=0; j<=100; j++){
			if(map[i][j]) ans++;
		}
	}
	printf("%d",ans);
}
