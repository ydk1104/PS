#include<stdio.h>
#include<algorithm>

int a[100001];

long long abs(long long x){
	return x>0 ? x : -x;
}

long long check(long long x, int N){
	long long sum = 0;
	for(int i=0; i<N; i++){
		sum += abs(x*i+a[0]-a[i]);
	}
	return sum;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	long long left = 0, right = (long long)1<<60;
	while(left+5<right){
		long long mid = (left+right)/2;
		long long c1 = check(mid, N), c2 = check(mid+1, N);
		if(c1==c2){
			left = mid;
			right = mid+1;
		}
		if(c1>c2){
			left = mid;
		}
		else right = mid+1;
	}
	long long ans = check(left, N);
	for(int i=left+1; i<=right; i++) ans = std::min(ans, check(i, N));
	printf("%lld", ans);
}
