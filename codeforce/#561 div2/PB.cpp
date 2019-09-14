#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	int i=5;
	for(; i*i<=N; i++){
		if(N%i==0) goto v;
	}
	printf("-1");
	return 0;
	v:
//		printf("%d",i);
	char a[5] = {'a', 'e', 'i', 'o', 'u'};
	for(int j=0; j<N/i; j++){
		for(int k=0; k<i; k++){
			printf("%c",a[(j+k)%5]);
		}
//		printf("\n");
	}
}
