#include<stdio.h>

int main(void){
	int check[42] = {0, };
	int ans=0;
	for(int i=1; i<=10; i++){
		int x;
		scanf("%d", &x);
		if(!check[x%42]) ans++;
		check[x%42]++;
	}
	printf("%d", ans);
}
