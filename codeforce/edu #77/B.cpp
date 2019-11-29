#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	while(N--){
		int x,y,ans=1;
		scanf("%d %d", &x, &y);
		if(x>y){
			int temp = x;
			x = y;
			y = temp;
		}
		if((x+y)%3) ans = 0;
		else{
			if(x*2<y) ans=0;
		}
		printf("%s\n", ans?"YES":"NO");
	}
}
