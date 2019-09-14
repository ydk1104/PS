#include<stdio.h>

int max, ans;

int main(void){
	for(int i=1; i<=9; i++){
		int temp;
		scanf("%d", &temp);
		if(temp>max){
			max = temp;
			ans = i;
		}
	}
	printf("%d\n%d", max, ans);
}
