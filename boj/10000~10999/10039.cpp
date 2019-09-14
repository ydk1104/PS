#include<stdio.h>

int main(void){
	int score = 0;
	int a;
	for(int i=1; i<=5; i++){
		scanf("%d", &a);
		if(a<=40){
			score += 40;
		}
		else{
			score += a;
		}
	}
	printf("%d", score/5);
}
