#include<stdio.h>

int main(void){
	int a,b;
	scanf("%d %d", &a, &b);
	int ans=1;
	for(int i=a, sum=(a*(a-1)/2)%14579; i<=b; i++){
		sum += i;
		ans *= sum;
		ans %= 14579;
	}
	printf("%d",ans);
}
