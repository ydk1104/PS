#include<stdio.h>
#include<algorithm>

using namespace std;

int a[500001];

int main(void){
	int N, M, x;
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	sort(a, a+N);
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		scanf("%d", &x);
		if(binary_search(a, a+N, x)) printf("1");
		else printf("0");
		printf(" ");
	}
}
