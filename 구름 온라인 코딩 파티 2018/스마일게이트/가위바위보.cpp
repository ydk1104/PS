#include<stdio.h>

int main(void){
	int a[5] = {0, };
	int check[4] = {0, };
	for(int i=0; i<=4; i++){
		scanf("%d", &a[i]);
		check[a[i]] ++;
	}
	for(int i=1; i<=3; i++){
		if(check[i]>0){
			check[0] ++;
		}
	}
	if(check[0] == 1 || check[0] == 3){
		printf("0");
	}
	else{
		for(int i=1; i<=3; i++){
			if(check[i] == 0){
				printf("%d", check[(i+1)%3+1]);
			}
		}
	}
}
