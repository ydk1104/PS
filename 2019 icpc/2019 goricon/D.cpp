#include<stdio.h>

int arr[200001];

void plus(int* ptr, int p, int N){
	if(ptr >= arr+N) ptr -= N;
	*ptr += p;
}

int at(int* ptr, int N){
	if(ptr >= arr+N) ptr -= N;
	return *ptr;
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++) scanf("%d", &arr[i]);
	int* ptr = arr;
	while(M--){
		int t,i, j;
		scanf("%d %d", &t, &i);
		if(t==1) scanf("%d", &j), plus(ptr+i-1, j, N);
		if(t==3) ptr += i;
		if(t==2) ptr -= i;
		if(ptr<arr) ptr += N;
		if(ptr>=arr+N) ptr -= N;
//		for(int i=0; i<N; i++) printf("%d ",at(ptr+i, N));
//		printf("test \n");
	}
	for(int i=0; i<N; i++) printf("%d ",at(ptr+i, N));
}
