#include<stdio.h>
#define ll long long int

int N, M, a[1000001];

int main(void){
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++) scanf("%d", &a[i]);
	int flag = 0;
	if(N%2==0) flag = a[M-1]%2;
	else{
		for(int i=0; i<M; i++){
			flag += a[i]%2;
		}
	}
//	printf("%d", flag);
	if(flag%2 == 0) printf("even");
	else printf("odd");
}
