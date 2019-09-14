#include<stdio.h>

int main(void){
	int N, L;
	scanf("%d %d", &N, &L);
	int i=L;
	int a[100];
	while(i<=100){
		int j=i;
		a[j] = N / i;
		int sum = a[j];
		for(; j>1; j--){
			a[j-1] = a[j] - 1;
			sum += a[j-1];
		}
		while(sum<N){
			a[j] += i;
			j++;
			sum += i;
			if(j==i+1){
				j=1;
			}
		}
		if(sum==N && a[j]>-1){
			for (int k=0; k<i; k++){
				printf("%d ", a[(k+j-1)%i+1]);
			}
			i = 200;
		}
		i++;
	}
	if (i!= 201){
		printf("-1");
	}
	return 0;
}
