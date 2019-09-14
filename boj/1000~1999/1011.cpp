#include<stdio.h>

int main(void){
	int T;
	scanf("%d", &T);
	for (int i=1; i<=T; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		long long int d = b-a;
		long long int j=1;
		while (d>=j*j){
			j++;
		}
		j--;
		d = d - j*j;
		if(d%j==0){
			j = 2 * j + d/j - 1;
		}
		else{
			j = 2 * j + d/j;
		}
		printf("%lld\n", j);
	}
}
