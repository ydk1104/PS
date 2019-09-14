#include<stdio.h>

int sum, ans, a, b;

int main(void){
	for(int i=0; i<4; i++){
		scanf("%d %d", &a, &b);
		sum += b-a;
		ans = sum>ans ? sum : ans;
	}
	printf("%d", ans);
}
