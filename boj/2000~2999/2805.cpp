#include<stdio.h>
#define MAX 1000000000

long long int N, M;
int tree[1000001];

void cut(int left, int right){
	if(left+1 == right){
		printf("%d", left);
		return;
	}
	int mid = (left+right+1)/2;
	long long int wood = 0;
	for(int i=0; i<N; i++){
		int temp = tree[i] - mid;
		if(temp>0) wood += temp;
	}
	if(wood>=M) return cut(mid, right);
	return cut(left, mid);
}

int main(void){
	scanf("%lld %lld", &N, &M);
	for(int i=0; i<N; i++) scanf("%d", &tree[i]);
	cut(0, MAX);
}
