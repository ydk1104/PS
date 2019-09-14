#include<stdio.h>
#include<algorithm>

int main(void){
	int a[3];
	for(int i=0; i<3; i++) scanf("%d",&a[i]);
	std::sort(a,a+3);
	if(*a+a[1]+a[2] != 180){
		printf("Error");
	}
	else{
		if(*a==a[2]) printf("Equilateral");
		else if(*a!=a[1] && a[1]!=a[2]) printf("Scalene");
		else printf("Isosceles");
	}
}
