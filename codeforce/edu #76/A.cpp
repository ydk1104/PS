#include<stdio.h>

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		int n,x,a,b;
		scanf("%d %d %d %d", &n, &x, &a, &b);
		if(a>b){
			int temp = a;
			a = b;
			b = temp;
		}
		while(b < n && x) b++, x--;
		while(a > 1 && x) a--, x--;
		printf("%d\n", b-a);
	}
}
