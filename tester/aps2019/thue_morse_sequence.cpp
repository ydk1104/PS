#include<stdio.h>
#include<string.h>

int main(void){
	long long k;
	scanf("%lld", &k);
	k--;
	int ans = 0;
	while(k){
		if(k%2) ans ^= 1;
		k/=2;
	}
	printf("%d\n",ans);
}
