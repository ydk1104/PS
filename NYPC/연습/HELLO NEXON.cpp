#include<stdio.h>
#include<string.h>

int main(void){
	int N, M;
	char s[6];
	int cnt = 0; 
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			scanf("%5s", &s);
			if(!strcmp("NEXON", s)) cnt++;
		}
	}
	printf("%d", cnt);
}
