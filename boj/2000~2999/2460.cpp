#include<stdio.h>

int main(void){
	int sum=0;
	int max=0;
	for(int i=0; i<9; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		sum+=(y-x);
		max=sum>max?sum:max;
	}
	printf("%d",max);
}
