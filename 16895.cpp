#include<stdio.h>

int arr[1001];

int main(void){
	int N;
	scanf("%d", &N);
	int num = 0, ans = 0;
	for(int i=0; i<N; i++) scanf("%d", &arr[i]), num ^= arr[i];
	for(int i=0; i<N; i++) if(arr[i] > (num ^ arr[i])) ans++;
	printf("%d", ans);
}
