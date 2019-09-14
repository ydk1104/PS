#include<stdio.h>

int main(void){
	int hour, min, plus;
	scanf("%d %d\n%d", &hour, &min, &plus);
	min += plus;
	hour += min/60;
	min %= 60;
	hour %= 24;
	printf("%d %d", hour, min);
}
