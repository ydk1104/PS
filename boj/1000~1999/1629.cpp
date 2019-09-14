#include<stdio.h>

int main(void){
	long long int a[40], b[40], c;
	scanf("%lld %lld %lld", &a[0], &b[0], &c);
	a[0] %= c;
	int cnt = 1;
	while(b[0]>0){
		a[cnt] = a[cnt-1] * a[cnt-1];
		a[cnt] %= c;
		b[cnt] = b[0]%2;
		b[0] /= 2;
		cnt++;
	}
	long long int ans = 1;
	for(int i=1; i<cnt; i++){
		if(b[i] == 1){
			ans *= a[i-1];
			ans %= c;
		}
	}
	printf("%lld", ans);
}
