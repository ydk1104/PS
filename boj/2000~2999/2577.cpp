#include<stdio.h>

int main(void){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int pro = a*b*c;
	int ans[10] = {0, };
	while(pro>0){
		ans[pro%10]++;
		pro /= 10;
	}
	for(int i=0; i<=9; i++){
		printf("%d\n", ans[i]);
	}
	return 0;
}
