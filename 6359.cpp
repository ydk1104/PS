#include<stdio.h>

int main(void){
	int T;
	scanf("%d", &T);
	for(int ii=1; ii<=T; ii++){
		int N;
		scanf("%d", &N);
		int ans = 0;
		for(int i=1;i*i<=N;i++){
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
