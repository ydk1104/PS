#include<stdio.h>
#include<algorithm>

int abs(int x){
	if(x>0) return x;
	return -x;
}

int main(void){
	int N, M;
	int a[10001];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		scanf("%d", &a[i]);
	}
	std::sort(a, a+N);
	int ans=0, positive=0;
	while(a[positive]<0) positive++;
	for(int i=0; i<positive; i+=M){
		ans += 2*abs(a[i]);
	}
	for(int i=N-1; i>=positive; i-=M){
		ans += 2*abs(a[i]);
	}
	int max = abs(a[0]) > abs(a[N-1]) ? abs(a[0]) : abs(a[N-1]);
	printf("%d", ans-max);
}
