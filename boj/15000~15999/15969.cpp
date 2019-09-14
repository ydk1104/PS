#include<stdio.h>
#include<algorithm>

int main(void){
	int N, score[1001]; scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &score[i]);
	std::sort(score, score+N);
	printf("%d", score[N-1]-score[0]);
}
