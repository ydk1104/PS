#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	if(N%2){
		for(int i=0; i<N; i++) printf("*");
		char s[101] = {0, };
		for(int i=0; i<N; i++) s[i]=' ';
		for(int i=0; i<N/2+1; i++){
			s[N-i] = '*';
			s[N+i] = '*';
			printf("\n%s", s+N/2+1);
			s[N-i] = ' ';
			s[N+i] = ' ';			
		}
	}
	else printf("I LOVE CBNU");
}
