#include<stdio.h>

int main(void){
	int N, K, a[101], reader=1;
	scanf("%d %d", &N, &K);
	for(int i=1; i<=N; i++) a[i] = i;
	for(int i=0; i<K; i++){
		int x;
		scanf("%d", &x);
		int now = (x-1)%(N-i)+1;
		for(int i=1; i<=now; i++, reader++) if(a[(i+reader-1)%N+1]==0) now++;
		a[reader=(reader-1)%N+1] = 0;
		printf("%d ",reader);
		reader++;
	}
}
