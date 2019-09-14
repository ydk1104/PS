#include<stdio.h>
#include<algorithm>

int a[200001];

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		int N;
		scanf("%d", &N);
		for(int i=0; i<N; i++) scanf("%d", &a[i]);
		std::sort(a, a+N);
		int i=N-2;
		while(i && a[N-2] <= i) i--;
		printf("%d\n", i);
	}
}
