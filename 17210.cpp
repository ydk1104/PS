#include<stdio.h>

int main(void){
	long long N;
	scanf("%lld",&N);
	int type;
	scanf("%d", &type);
	if(N>5) printf("Love is open door");
	else{
		for(;N-->1;){
			type=1-type;
			printf("%d\n",type);
		}
	}
}
