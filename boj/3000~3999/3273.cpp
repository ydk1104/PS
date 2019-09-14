#include<stdio.h>
#include<stdlib.h>

int num[100001];

int compare(const void *a, const void *b){
	int *pa = (int*) a;
	int *pb = (int*) b;
	if(*pa>*pb) return 1;
	if(*pa == *pb) return 0;
	return -1;
}

int bisearch(int *num, int left, int right, int tar){
	int mid = (left+right)/2;
	if (num[mid] == tar) return 1;
	if (left>=right) return 0;
	if(num[mid]<tar) return bisearch(num, mid+1, right, tar);
	else return bisearch(num, left, mid-1, tar);
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &num[i]);
	}
	int x;
	scanf("%d", &x);
	qsort(num, N, sizeof(int), compare);
	int cnt = 0;
	for(int i=0; num[i]*2 < x; i++){
		cnt += bisearch(num, 0, N, x-num[i]);
	}
	printf("%d", cnt);
}
