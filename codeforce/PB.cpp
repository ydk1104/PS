#include<stdio.h>

long long int sum[2];
int a[200001];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &a[i]);
		sum[i%2] += a[i];
	}
	int ans=0;
	for(int i=0; i<N; i++){
		sum[i%2] -= a[i];
		if(sum[0] == sum[1]) ans++;
		sum[1-i%2] += a[i];
	}
	printf("%d", ans);
}
