#include<stdio.h>

int main(void){
	int N, x, ans=0;
	scanf("%d", &N);
	for(int i=0; i<5; i++){
		scanf("%d", &x);
		if(N==x) ans++;
	}
	printf("%d", ans);
}
