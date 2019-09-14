#include<stdio.h>
#define min(a,b) (a<b) ? a : b

int main(void){
	int ham[3];
	int soda;
	int cola;
	int ans = 2000;
	for(int i=0; i<3; i++){
		scanf("%d", &ham[i]);
		ans = min(ans, ham[i]);
	}
	scanf("%d %d", &soda, &cola);
	ans += min(soda, cola);
	ans -= 50;
	printf("%d", ans);
}
