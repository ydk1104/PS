#include<stdio.h>

int main(void){
	char name[11];
	int age, kg;
	do{
		scanf("%s %d %d", &name, &age, &kg);
		if(age){
			printf("%s %snior\n", name, age>17||kg>79 ? "Se" : "Ju");
		}
	}while(age);
}
