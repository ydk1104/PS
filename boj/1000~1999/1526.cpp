#include<stdio.h>

int check(int x){
	while(x>0){
		if((x%10!=4)&&(x%10!=7)) return 0;
		x/=10;
	}
	return 1;
}

int main(void){
	int N, max;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		if(check(i)) max = i;
	}
	printf("%d", max);
}
