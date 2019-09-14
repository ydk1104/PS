#include<stdio.h>

int main(void){
	int Aa, Ha;
	int Ab, Hb;
	scanf("%d %d\n%d %d", &Aa, &Ha, &Ab, &Hb);
	while((Ha>0) && (Hb>0)){
		Ha -= Ab;
		Hb -= Aa;
	}
	if((Ha<=0) && (Hb<=0)){
		printf("DRAW");
	}
	else if(Ha<=0){
		printf("PLAYER B");
	}
	else{
		printf("PLAYER A");
	}
}
