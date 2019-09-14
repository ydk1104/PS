#include<stdio.h>

int main(void){
	int N, cnt=0, temp;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%1d", &temp);
		cnt+=temp;
	}
	printf("%d", cnt);
}
