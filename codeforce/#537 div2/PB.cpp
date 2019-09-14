#include<stdio.h>
#include<algorithm>
#define min(a,b) ((a)>(b) ?(b) :(a))
#define max(a,b) ((a)<(b) ?(b) :(a))

using namespace std;

int n, k, m;
int a[100001];

int main(void){
	scanf("%d %d %d", &n, &k, &m);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a+n);
	long long int sum = 0;
	for(int i=0; i<n; i++){
		sum += a[i];
	}
	double ans = 0;
	for(int i=0; i<n; i++){
		sum += min(k*(n-i), m);
		double temp = double(sum) / double(n-i);
		ans = max(ans, temp);
//		printf("%d %lf %lf\n", sum, temp, ans);
		sum -= min(k*(n-i), m);
		m--;
		sum -= a[i];
	}
	printf("%lf", ans);
}
