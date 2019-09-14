#include<stdio.h>

int main(void){
	int health, mana;
	scanf("%d %d", &health, &mana);
	int money;
	scanf("%d", &money);
	int health_cnt=0;
	while(money%mana){
		money -= health;
		health_cnt++;
	}
	printf("%d %d", health_cnt, money/mana);
}
