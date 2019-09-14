#include<stdio.h>

int main(void){
	int a[3];
	for(int i=0; i<=2; i++){
		scanf("%d", &a[i]);
	}
	for(int i=0; i<=2; i++){
		for(int j=i+1; j<=2; j++){
			if(a[i]>a[j]){
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		printf("%d ",a[i]);
	}
}
