#include<stdio.h>
#define xx first
#define yy second
#include<vector>
#include<algorithm>
#include<tuple>

std::vector<std::pair<int, int> > v;
int a,b, ans=1e9, dp[100001];

int main(void){
	int N=250;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x=251,y=1;
		scanf("%d %d", &x, &y);
		v.push_back({x,y});
		a += y;
	}
	ans = a;
	std::sort(v.begin(), v.end());
	for(auto x:v){
		int now = x.first; // now = a[i];
		for(int i=a; i>=now; i--){
			dp[i] = std::max(dp[i], dp[i-now] + x.second);
			ans = std::min(ans, std::max(a-dp[i], i));
//			printf("%d %d %d\n", ans, dp[i], i);
		}
	}
	printf("%d", ans);
}
