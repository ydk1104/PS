#include<stdio.h>

int main(void){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		int N = 0;
		float score[1001] = {0, };
		scanf("%d", &N);
		for(int i=1; i<=N; i++){
			scanf("%f", &score[i]);
			score[0] += score[i];
		}
		score[0] /= N;
		double cnt = 0;
		for(int i=1; i<=N; i++){
			if(score[i]>score[0]){
				cnt++;
			}
		}
		printf("%.3f%%\n", cnt*100/N);
	}
}
