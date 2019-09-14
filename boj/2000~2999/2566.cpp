#include<stdio.h>

int main(void){
	int max=0, x=0, y=0;
	for(int i=1; i<=9; i++){
		for(int j=1; j<=9; j++){
			int temp;
			scanf("%d", &temp);
			if(temp>max){
				max=temp;
				x=i;
				y=j;
			}
		}
	}
	printf("%d\n%d %d",max,x,y);
}
