#include<stdio.h>
#include<algorithm>

int main(void){
	int a[3];
	while(1){
		scanf("%d %d %d", a, a+1, a+2);
		if(!*a) break;
		if(*a == a[1] && *a == a[2]) printf("Equilateral");
		else{
			std::sort(a,a+3);
			if(*a+a[1] <= a[2]) printf("Invalid");
			else if(*a==a[1] || a[1]==a[2]) printf("Isosceles");
			else printf("Scalene");
		}
		printf("\n");
	}
}
