#include<stdio.h>

int find(int x){
	int temp = (x%4==1 || x%4==2);
	int now = 2;
	while(now<=x){
		if(x%(now*2) >= now && x%2==0) temp ^= now;
		now <<= 1;
	}
	return temp;
}

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		int s,e;
		scanf("%d %d", &s, &e);
		printf("%d\n", find(e)^find(s-1));
	}
}
