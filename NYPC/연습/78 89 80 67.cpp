#include<stdio.h>

int main(void){
	int N;
	char c[1001];
	scanf("%d", &N);
	//���ڸ� �Է¹޾� ���ڷ� ��� 
	for(int i=0; i<N; i++){
		scanf("%d", &c[i]);
	}
	for(int i=0; i<N; i++){
		printf("%c ", c[i]);
	}
	
}
