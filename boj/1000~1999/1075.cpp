#include<stdio.h>

int main(void){
	int N, F;
	scanf("%d %d", &N, &F);
	int ans = N%100 - N%F;
	while(ans<0){
		ans+=F;
	}
	while(ans>=F){
		ans-=F;
	}
	if(ans<10){
		printf("0%d", ans);
	}
	else{
		printf("%d", ans);
	}
	return 0;
}
