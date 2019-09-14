#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	int a[101]={0,};
	int ans=0;
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	for(int i=0; i<N; i++){
		int row=0;
		while(a[i]) i++,row++;
		ans += (row+1)*row/2;
	}
	printf("%d", ans);
}
