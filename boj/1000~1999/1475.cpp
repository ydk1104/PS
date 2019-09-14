#include<stdio.h>
#define max(a,b) (a<b ? b : a)

int count(int N){
	if(N==0) return 1;
	int a[10] = {0, };
	for(;N>0;N/=10) a[N%10]++;
	a[6] = (a[6]+a[9]+1)/2;
	int ans = 0;
	for(;N<9;N++) ans=max(ans,a[N]);
	return ans;
}

int main(void){
	int N;
	scanf("%d", &N);
	printf("%d", count(N));
}
