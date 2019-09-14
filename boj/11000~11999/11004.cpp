#include<stdio.h>
#include<stdlib.h>

int a[5000001];
int N, K;
int cnt;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int sort(int left, int right){
	int temp = (left+right)/2;
	int j = left;
	swap(&a[temp], &a[j]);
	for(int i=left+1; i<=right; i++){
		if(a[left] > a[i]){
			j++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[left], &a[j]);
	if(j==K) return a[j];
	if(j<K) return sort(j+1, right);
	return sort(left, j-1);
}

int main(void){
	scanf("%d %d", &N, &K);
	K--;
	for(int i=0; i<N; i++){
		scanf("%d", &a[i]);
	}
	printf("%d", sort(0, N-1));
}
