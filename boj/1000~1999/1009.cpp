#include<stdio.h>

int main(void){
	int T;
	scanf("%d", &T);
	for (int ii=1; ii<=T; ii++){
		int a, b;
		int x[11];
		scanf("%d %d", &a, &b);
		if(a%10==0){
			printf("10\n");
		}
		else{
			x[0]=a;
			a = a%10;
			x[1]=a;
			a = (a * x[0]) % 10;
			int i = 2;
			while (a != x[1]){
				x[i] = a;
				a = (a * x[0]) % 10;
				i++;
			}
			i--;
			b = b % i;
			if (b==0){
				printf("%d\n", x[i]);
			}
			else{
				printf("%d\n", x[b]);
			}
		}
	}
	return 0;
}
