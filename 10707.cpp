#include<stdio.h>
#include<algorithm>

int main(void){
	int a,b,c,d,e;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	printf("%d",std::min(a*e,b+(e-c>0?e-c:0)*d));
}
