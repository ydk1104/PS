#include<stdio.h>

int main(void){
	int N, K, ans=0, cnt=0;
	scanf("%d %d", &N, &K);
	int temp = K;
	while(K-- && N){
		if(N%10) ans++, K++;
		else cnt++;
		N/=10;
	}
	if(cnt && cnt < temp) ans += cnt-1;
	printf("%d", ans);
}
