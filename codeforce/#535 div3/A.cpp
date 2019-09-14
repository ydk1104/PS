#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if(a!=c) printf("%d %d\n", a, c);
		else if(a!=d) printf("%d %d\n", a, d);
		else if(b!=c) printf("%d %d\n", b, c);
		else if(b!=d) printf("%d %d\n", b, d);
	}
}
