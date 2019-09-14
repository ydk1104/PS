#include<stdio.h>

int a[31];

int main(void){
	for(int i=1;i<=28; i++){
		int x;
		scanf("%d", &x);
		a[x]++;
	}
	for(int i=1; i<=30; i++){
		if(!a[i]) printf("%d\n",i);
	}
}
