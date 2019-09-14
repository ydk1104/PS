#include<stdio.h>
#include<algorithm>

using namespace std;

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	int a[8];
	for(int i=0; i<N; i++) a[i]=i+1;
	int prev[8] = {0, };
	do{
		int flag = 0;
		for(int i=0; i<M; i++){
			if(a[i] != prev[i]) flag = true;
			if(i!=0 && a[i-1]>a[i]) goto v;
		}
		if(!flag) continue;
		for(int i=0; i<M; i++) prev[i] = a[i], printf("%d ", a[i]);
		printf("\n");
		v:
			continue;
	}while(next_permutation(a, a+N));
}
