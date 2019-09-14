#include<stdio.h>
#include<algorithm>

int a[10001];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	int check = std::prev_permutation(a, a+N);
	if(check){
		for(int i=0; i<N; i++) printf("%d ",a[i]);
	}
	else printf("-1");
}
