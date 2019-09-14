#include<stdio.h>

int main(void){
	int x, y;
	char s[2][5] = {{"No"}, {"Yes"}};
	scanf("%d %d",&x, &y);
	while(x!=0 && y!=0){
		printf("%s\n", s[x>y]);
		scanf("%d %d",&x, &y);
	}
}
