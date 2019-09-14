#include<stdio.h>

int p[10001];

void find(int N){
	if(N==4){
		printf("2 2\n");
		return;
	}
	int ans;
	for(int i=3; i<=N/2; i++){
		if(p[i] == 0 && p[N-i] == 0){
			ans = i;
		}
	}
	printf("%d %d\n", ans, N-ans);
	return;
}

int main(void){
	for(int i=4; i<=10000; i+=2){
		p[i] = 1;
	}
	for(int i=3; i<=10000; i++){
		if(p[i] == 0){
			for(int j=3; i*j<=10000; j++){
				p[i*j] = 1;
			}
		}
	}
	int T;
	scanf("%d", &T);
	for(int i=1; i<=T; i++){
		int N;
		scanf("%d", &N);
		find(N);
	}
}
