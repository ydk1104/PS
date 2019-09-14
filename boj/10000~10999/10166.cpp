#include<stdio.h>

int chair[2001][2001] = {0, };

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	int ans = 0;
	int flag = 0;
	for(int i=N; i<=M; i++){
		ans += i;
	}
	for(int i=1; i<=M; i++){
		for(int j=1; j<=i; j++){
			if(chair[i][j] == 0){
				int k = i;
				int l = j;
				while(k<=M){
					if(k>=N){
						ans--;
						flag = 1;
					}
					chair[k][l] = 1;
					k += i;
					l += j;
				}
				ans += flag;
				flag = 0;
			}
		}
	}
	printf("%d", ans);
}
