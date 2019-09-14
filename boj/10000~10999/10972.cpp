#include<stdio.h>
#include<algorithm>

int main(void){
	int N, a[10000];
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	if(std::next_permutation(a, a+N)){
		for(int i=0; i<N; i++) printf("%d ", a[i]);
	}
	else printf("-1");
}
