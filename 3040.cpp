#include<stdio.h>

int main(void){
	int a[9], sum=0;
	for(int i=0; i<9; i++) scanf("%d", &a[i]), sum+=a[i];
	for(int i=0; i<9; i++){
		for(int j=i+1; j<9; j++){
			if(sum - a[i] - a[j] == 100){
				for(int k=0; k<9; k++){
					if(k!=i && k!=j) printf("%d\n", a[k]);
				}
			}
		}
	}
}
