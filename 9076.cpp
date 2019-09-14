#include<stdio.h>
#include<algorithm>

int main(void){
	int N;
	scanf("%d", &N);
	while(N--){
		int a[5];
		for (int i=0; i<5; i++) scanf("%d",&a[i]);
		std::sort(a,a+5);
		if(a[3]-a[1]>=4) printf("KIN\n");
		else printf("%d\n",a[1]+a[2]+a[3]);
	}
}
