#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	int a[101];
	for(int i=0; i<N; i++){
		scanf("%d", &a[i]);
	}
	if(N<=2 && a[1] != a[0]) printf("A");
	else{
		if(a[1] == a[0]){
			for(int i=1; i<N; i++){
				if(a[i] != a[i-1]){
					printf("B");
					return 0;
				}
			}
			printf("%d", a[0]);
			return 0;
		}
		int r = (a[2]-a[1]) / (a[1]-a[0]);
		int A = a[1] - a[0];
		for(int i=1; i<N; i++){
			if(A != a[i]-a[i-1]){
				printf("B");
				return 0;
			}
			A *= r;
		}
		printf("%d", a[N-1] + A);
	}
}
