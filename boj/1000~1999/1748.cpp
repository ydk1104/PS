#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	int len=1, cnt=0, ans=0;
	while(cnt*10+9<N)cnt=cnt*10+9,len++;
	while(N){
		ans += (N-cnt)*len;
		N=cnt;
		cnt/=10;
		len--;
	}
	printf("%d",ans);
}
