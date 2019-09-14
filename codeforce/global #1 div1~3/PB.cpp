#include<stdio.h>
#include<algorithm>
#define min(a,b) ((a)>(b) ?(b) :(a))
#define max(a,b) ((a)<(b) ?(b) :(a))

using namespace std;

long long int n, k, m;
int a[100001];

int main(void){
	scanf("%lld %lld %lld", &n, &k, &m);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a+n);
	long long int sum = 0;
	for(int i=0; i<n; i++){
		sum += a[i];
	}
	double ans = 0;
	for(int i=0; i<n && i<=m; i++){
		sum += min(k*(n-i), m-i);
		double temp = double(sum) / double(n-i);
		ans = max(ans, temp);
//		printf("%d %lf %lf\n", sum, temp, ans);
		sum -= min(k*(n-i), m-i);
		sum -= a[i];
	}
	printf("%lf", ans);
}
