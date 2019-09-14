#include<stdio.h>

int a[2001];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		int x;
		scanf("%d", &x);
		a[x+1000]++;
	}
	for(int i=-1000; i<=1000; i++){
		if(a[i+1000]) printf("%d ",i);
	}
}
