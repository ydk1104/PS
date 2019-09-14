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
		int flag=0;
		for(int i=0; i<M; i++){
			if(i>0 && a[i]<a[i-1]){
				flag=0;
				break;
			}
			if(a[i] != prev[i]) flag=1;
		}
		if(!flag) continue;
		for(int i=0; i<M; i++) prev[i] = a[i], printf("%d ", a[i]);
		printf("\n");
	}while(next_permutation(a, a+N));
}
