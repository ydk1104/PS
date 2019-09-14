#include<stdio.h>

int main(void){
	int score[201][4] = {0, };
	int check[101][4] = {0, };
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		for(int j=0; j<3; j++){
			scanf("%d", &score[i][j]);
			check[score[i][j]][j]++;
		}
	}
	for(int i=1; i<=N; i++){
		for(int j=0; j<3; j++){
			if(check[score[i][j]][j] == 1) score[i][3] += score[i][j];
		}
		printf("%d\n", score[i][3]);
	}
}
