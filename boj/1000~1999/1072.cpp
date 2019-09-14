#include<stdio.h>

int main(void){
	long long a,b;
	scanf("%d %d", &a, &b);
	int z=(b*100)/a;
	long long cnt=0;
	long long left=0, right=(long long)1<<50;
	while(left<=right){
		long long mid = (left+right+1)/2;
		if((b+mid)*100/(a+mid) > z){
			right = mid-1;
			cnt = mid;
		}
		else{
			left = mid+1;
		}
	}
	if(cnt)	printf("%lld",cnt);
	else printf("-1");
}
