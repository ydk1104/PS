#include<stdio.h>
#include<algorithm>

const int MAX = 100010;

// CHT code by kks227

struct LinearFunc{
	long long a,b;
	double s;
	LinearFunc() : LinearFunc(1,0){}
	LinearFunc(long long a1, long long b1) : a(a1),b(b1),s(0){}
};

inline double cross(LinearFunc &f, LinearFunc &g){
	return (g.b-f.b)/(f.a-g.a);
}

int main(){
	int N, A[MAX], B[MAX];
	scanf("%d", &N);
	for(int i=0; i<N-1; i++){
		scanf("%lld", &a[i]);
		sum[i+1] = sum[i] + a[i];
	}
	for(int i=0; i<N-1; i++) scanf("%lld %lld", &p[i], &w[i]);
	long long dp[MAX] = {0,};
	LinearFunc f[MAX];
	int top = 0;
	for(int i=1; i<N; i++){
		LinearFunc g(sum[i-1]-sum[i-,dp[i-1]);
	}
}
