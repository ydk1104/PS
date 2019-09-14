#include<stdio.h>

int main(void){
	int n, k;
	while(scanf("%d %d", &n, &k) != EOF){
		int ans = n;
		while(n>=k){
			ans += n/k;
			int temp = n/k;
			n%=k;
			n+=temp;
		}
		printf("%d\n", ans);
	}
}
