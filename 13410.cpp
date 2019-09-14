#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))

int main(void){
	int N, M, ans=0;
	scanf("%d %d", &N, &M);
	for(int i=1; i<=M; i++){
		int now = N*i;
		int temp = 0;
		while(now>0){
			temp*=10;
			temp+=now%10;
			now/=10;
		}
		ans = max(ans, temp);
	}
	printf("%d", ans);
}
