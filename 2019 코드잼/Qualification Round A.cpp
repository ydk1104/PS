#include<stdio.h>

int main(void){
	int T;
	scanf("%d", &T);
	for(int i=1; i<=T; i++){
		long long x, a=0, b=0;
		scanf("%lld", &x);
		long long now = 1;
		while(x>0){
			if(x%10 == 4){
				a+=3*now, b+=1*now;
			}
			else a+=x%10*now;
			now*=10, x/=10;
		}
		printf("Case #%d : %lld %lld\n", i, a, b);
	}
}
