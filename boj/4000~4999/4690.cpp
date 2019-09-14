#include<stdio.h>

int main(void){
	for(int i=1; i<=100; i++){
		for(int j=2; j<=i; j++){
			for(int k=j; k<=i; k++){
				for(int l=k; l<=i; l++){
					if(i*i*i == j*j*j+k*k*k+l*l*l){
						printf("Cube = %d, Triple = (%d,%d,%d)\n", i, j, k, l);
					}
				}
			}
		}
	}
}
