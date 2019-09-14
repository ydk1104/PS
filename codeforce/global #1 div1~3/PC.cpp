#include<stdio.h>

void ans(int N){
	int i = 1;
	while(i<N){
		i *= 2;
		i++;
	}
	if(i!=N){
		printf("%d\n", i);
		return;
	}
	for(int j=3; j*j<N; j++){
		if(N%j == 0){
			printf("%d\n", N/j);
			return;
		}
	}
	printf("1\n");
	return;
}

int main(void){
	int Q; scanf("%d", &Q);
	while(Q--){
		int N;
		scanf("%d", &N);
		ans(N);
	}
}
