#include<stdio.h>

int main(void){
	int N;
	char c[1001];
	scanf("%d", &N);
	//숫자를 입력받아 문자로 출력 
	for(int i=0; i<N; i++){
		scanf("%d", &c[i]);
	}
	for(int i=0; i<N; i++){
		printf("%c ", c[i]);
	}
	
}
