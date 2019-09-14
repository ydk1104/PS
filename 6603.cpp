#include<stdio.h>

int a[15];
int k = 1;

void check(int N){
	int cnt = 1;
	int b[15] = {0, };
	while(N>0){
		b[cnt] = N%2;
		b[0] += b[cnt];
		cnt++;
		N /= 2;
	}
	if(b[0] == 6){
		for(int i=k; i>=1; i--){
			if(b[i] == 1){
				printf("%d ",a[i]);
			}
		}
	printf("\n");
	}
	return;
}

int main(void){
	while(k){
		scanf("%d", &k);
		for(int i=k; i>=1; i--){
			scanf("%d", &a[i]);
		}
		for(int i=1<<k; i>60; i--){
			check(i);
		}
		printf("\n");
	}
	return 0;
}
