#include<stdio.h>

char s[221], ans[22][221];

int main(void){
	int N;
	char s[221] = {0,};
	scanf("%d\n%s", &N, &s);
	int now = 0;
	for(int i=0; s[i]!=0; i+=2*N){
		for(int j=0; j<N; j++){
			ans[j][now] = s[i+j];
		}
		now++;
		for(int j=N-1; j>=0; j--){
			ans[j][now] = s[i+2*N-j-1];
		}
		now++;
	}
	for(int i=0; i<N; i++) printf("%s", ans[i]);
}
