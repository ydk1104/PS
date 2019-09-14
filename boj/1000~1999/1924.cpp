#include<stdio.h>

int main(void){
	int a, b;
	scanf("%d %d", &a, &b);
	int day = b;
	for(int i=1; i<a; i++){
		if(i==2){
			day += 28;
		}
		else if(((i%2==1)&&(i<=7))||((i%2==0)&&(i>=8))){
			day += 31;
		}
		else{
			day += 30;
		}
	}
	day = day % 7;
	if(day == 0){
	printf("SUN");
	}
	else if(day == 1){
		printf("MON");
	}
	else if(day == 2){
		printf("TUE");
	}
	else if(day == 3){
		printf("WED");
	}
	else if(day == 4){
		printf("THU");
	}
	else if(day == 5){
		printf("FRI");
	}
	else if(day == 6){
		printf("SAT");
	}
	return 0;
}
