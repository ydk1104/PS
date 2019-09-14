#include<stdio.h>

int main(void){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int E=1, S=1, M=1;
	int cnt = 1;
	while(E!=a || S!=b || M!=c){
		E%=15; E++;
		S%=28; S++;
		M%=19; M++;
		cnt++;
	}
	printf("%d", cnt);
}
