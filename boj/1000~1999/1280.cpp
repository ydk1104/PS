#include<stdio.h>

long long int tsum[600001];
long long int tcnt[600001];
int max;

long long int sum(long long int a[], int L, int R, int now, int nL, int nR){
	if(L<=nL && R>=nR) return a[now];
	if(L>nR || R<nL) return 0;
	int mid = (nL + nR)/2;
	return sum(a, L, R, now*2, nL, mid) + sum(a, L, R, now*2+1, mid+1, nR);
}

void update(long long int a[], int i, long long int num){
	i += max/2;
	a[i] += num;
	while(i>1){
		i /= 2;
		a[i] = a[i*2] + a[i*2+1];
	}
}

int main(void){
	int N;
	scanf("%d", &N);
	long long int ans = 1;
	max = 1<<19;
	for(int i=1; i<=N; i++){
		int x;
		scanf("%d", &x);
		update(tcnt, x, 1);
		update(tsum, x, x);
		if(i==1) continue;
		long long int temp = 0;
		temp += sum(tcnt, 0, x-1, 1, 0, max/2-1) * x;
		temp -= sum(tsum, 0, x-1, 1, 0, max/2-1);
		temp += sum(tsum, x+1, max/2-1, 1, 0, max/2-1);
		temp -= sum(tcnt, x+1, max/2-1, 1, 0, max/2-1) * x;
		temp %= 1000000007;
		ans *= temp;
		ans %= 1000000007;
	}
	printf("%lld", ans);
}
