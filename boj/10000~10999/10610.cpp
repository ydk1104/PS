#include<stdio.h>

int check[10], sum;

int main(void){
	char N[100001];
	scanf("%s", &N);
	for(int i=0; N[i]!=0; i++){
		int x = N[i] - '0';
		check[x]++;
		sum += x;
	}
	if(!(sum%3) && check[0]){
		for(int i=9; i>=0; i--){
			for(; check[i]>0; check[i]--){
				printf("%d", i);
			}
		}
	}
	else printf("-1");
}
