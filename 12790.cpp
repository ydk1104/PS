#include<stdio.h>

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		int a[8];
		for(int i=0; i<8; i++) scanf("%d", &a[i]);
		for(int i=0; i<4; i++) a[i]+=a[i+4];
		for(int i=0; i<3; i++) (a[i]<(1-i/2))?a[i]=(1-i/2):0;
		printf("%d\n",a[0]+5*a[1]+2*a[2]+2*a[3]);
	}
}
