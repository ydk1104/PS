#include<stdio.h>
#define ll long long int

ll a[101];
int N;

int abs(ll x){
	if(x>0) return x;
	return -x;
}

void swap(ll *x, ll *y){
	ll temp = *x;
	*x = *y;
	*y = temp;
}

int com(int x, int y){
	int max = abs(a[N-1] - a[0]);
	for(int i=1; i<N; i++){
		max = max > abs(a[i] - a[i-1]) ? max : abs(a[i] - a[i-1]);
	}
	swap(&a[x], &a[y]);
	for(int i=0; i<N; i++){
		if(max < abs(a[i] - a[(i-1+N)%N])){
			return 1;
		}
	}
	return 0;
}

int main(void){
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%lld", &a[i]);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			for(int k=0; k<N; k++){
				if(com(j, k)) swap(&a[j], &a[k]);
			}
		}
	}
	for(int i=0; i<N; i++) printf("%lld ", a[i]);
}
