#include<stdio.h>

int main(void){
	int T;
	scanf("%d", &T);
	if(T%10) printf("-1");
	else printf("%d %d %d", T/300, (T%300)/60, (T%60)/10);
}
