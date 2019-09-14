#include<stdio.h>
#include<algorithm>

int main(void){
	int a[5];
	for(int i=0; i<5; i++) scanf("%d", &a[i]);
	std::sort(a, a+5);
	int sum=0;
	for(int i=0; i<5; i++) sum += a[i];
	printf("%d\n%d", sum/5,a[2]);
}
