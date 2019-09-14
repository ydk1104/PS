#include<stdio.h>

int main(void){
	int check[201];
	int temp;
	scanf("%d", &temp);
	while(temp!=-1){
		for(int i=0; i<=200; i++){
			check[i] = 0;
		}
		int a[21];
		a[0] = temp;
		check[temp] = 1;
		for(int i=1; i<=20; i++){
			a[i] = -2;
		}
		for(int i=1; a[i-1]!=0; i++){
			scanf("%d", &a[i]);
			check[a[i]] = 1;
		}
		int cnt = -1;
		for(int i=0; (i==0) || (a[i-1]!=0); i++){
			if(check[a[i]*2] == 1){
				cnt++;
			}
		}
		printf("%d\n", cnt);
		scanf("%d", &temp);
	}
}
