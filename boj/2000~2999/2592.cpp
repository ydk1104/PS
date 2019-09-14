#include<stdio.h>

int main(void){
	int cnt[101]={0,}, sum=0;
	for(int i=0; i<10; i++){
		int x;
		scanf("%d", &x);
		sum += x/10;
		cnt[x/10]++;
	}
	int max=0, ans;
	for(int i=0; i<=100; i++){
		if(max<cnt[i]) max=cnt[i], ans=i;
	}
	printf("%d\n%d",sum,ans*10);
}
