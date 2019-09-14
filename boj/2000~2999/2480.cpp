#include<stdio.h>
#include<algorithm>

int main(void){
	int a[3]; scanf("%d%d%d",&a[0],&a[1],&a[2]);
	std::sort(a,a+3);
	if(*a==a[1]&&a[1]==a[2]) printf("%d",10000+a[0]*1000);
	else if(*a==a[1]||a[1]==a[2]) printf("%d",1000+a[1]*100);
	else printf("%d",a[2]*100);
}
