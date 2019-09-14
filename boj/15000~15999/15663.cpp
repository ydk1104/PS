#include<stdio.h>
#include<algorithm>

using namespace std;

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	int a[8];
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	sort(a, a+N);
	int prev[8] = {0, };
	do{
		for(int i=0; i<M; i++){
			if(a[i] != prev[i]) goto v;
		}
		continue;
		v:
			for(int i=0; i<M; i++) prev[i] = a[i], printf("%d ", a[i]);
			printf("\n");
	}while(next_permutation(a, a+N));
}
