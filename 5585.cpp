#include<stdio.h>

int main(){
	int N;
	scanf("%d", &N);
	N=1000-N;
	int ans=0;
	int a[6] = {500, 100, 50, 10, 5, 1};
	for(int i=0; i<6; i++){
		ans += N/a[i];
		N%=a[i];
	}
	printf("%d", ans);
}
