#include<stdio.h>

int main(void){
	int x[3],y[3];
	for(int i=0; i<3; i++){scanf("%d %d", &x[i], &y[i]);}
	for(int i=0; i<3; i++){
		for(int j=i+1; j<3; j++){
			if(x[i] == x[j]) printf("%d ",x[0]+x[1]+x[2]-x[i]-x[j]);
		}
	}
	for(int i=0; i<3; i++){
		for(int j=i+1; j<3; j++){
			if(y[i] == y[j]) printf("%d ",y[0]+y[1]+y[2]-y[i]-y[j]);
		}
	}
}
