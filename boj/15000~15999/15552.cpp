#include<stdio.h>

int main(void){
	int T, a, b;
	scanf("%d", &T);
	for(int i=1; i<=T; i++){
		scanf("%d %d", &a, &b);
		printf("%d\n", a+b);
	}
	return 0;
}
