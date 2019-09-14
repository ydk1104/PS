#include<stdio.h>

int self[10001];

int SN(int a){
	if(self[a] == 1){
		return 1;
	}
	else{
		int b = a;
		while(a>0){
			b += a%10;
			a /= 10;
		}
		if(b<=10000){
			SN(b);
			self[b] = 1;
		}
	}
	return 0;
}

int main(void){
	for(int i=1; i<=10000; i++){
		if(!SN(i)){
			printf("%d\n", i);
		}
	}
}
