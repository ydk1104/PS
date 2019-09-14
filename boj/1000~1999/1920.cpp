#include<stdio.h>
#include<algorithm>

using namespace std;

int a[100001];

int BS(int ta, int left, int right){
	if(left > right) return 0;
	int mid = (left + right + 1) /2;
	if(ta == a[mid]) return 1;
	if(ta < a[mid]) return BS(ta, left, mid-1);
	return BS(ta, mid+1, right);
}

int main(void){
	int N, M;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a+N);
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		int x;
		scanf("%d", &x);
		if(BS(x, 0, N-1)) printf("1\n");
		else printf("0\n");
	}
}
