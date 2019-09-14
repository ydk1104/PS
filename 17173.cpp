#include<stdio.h>

int a[1001];
int check[1001];
int sum;

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++) scanf("%d", &a[i]);
	for(int i=1; i<=N; i++)
		for(int j=0; j<M; j++)
			if(i%a[j]==0) sum+=i, j=M;
	printf("%d", sum);
}
