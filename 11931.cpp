#include<stdio.h>
#include<algorithm>

int a[1000001];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &a[i]);
	}
	std::sort(a,a+N);
	for(int i=N; i; i--) printf("%d\n", a[i-1]);
}
