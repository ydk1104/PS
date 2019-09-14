#include<stdio.h>
#define MAX 2000000000

int a[1000001];
int b[1000001];
int c[2000001];

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	for(int i=0; i<M; i++) scanf("%d", &b[i]);
	int left=0, right=0, cnt=0;
	a[N]=MAX, b[M]=MAX;
	while(left<=N && right<=M){
		if(a[left]<b[right]) c[cnt++]=a[left++];
		else c[cnt++]=b[right++];
	}
	for(int i=0; i<N+M; i++) printf("%d ",c[i]);
}
