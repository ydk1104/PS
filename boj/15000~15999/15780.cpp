#include<stdio.h>

int main(void){
	int N, K;
	scanf("%d %d", &N, &K);
	int cnt = 0;
	for(int i=1; i<=K; i++){
		int temp;
		scanf("%d", &temp);
		cnt +=(temp+1)/2;
	}
	if(N<=cnt){
		printf("YES");
	}
	else{
		printf("NO");
	}
	return 0;
}
