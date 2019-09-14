#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	int ans=0;
	while(N--){
		int x, y;
		scanf("%d %d", &x, &y);
		ans += y%x;
	}
	printf("%d",ans);
}
