#include<stdio.h>
#include<vector>
#include<math.h>

const long long max = 1e6;
std::vector<std::vector<int> > v;
int dp[1000001];

void init(){
	v.push_back({0});
	v.push_back({0,0,0,0});
	long long l=1, r=1;
	int temp = 0;
	for(int i=2; i<=max; i++){
		if(r*r <= i) r++;
		if(l*l <= r-1) l++;
		while(v[r-1][dp[i]] - v[l-1][dp[i]]) dp[i]++;
		v.push_back(v.back());
		v.back()[dp[i]]++;
		if(dp[i] > temp) temp = dp[i];
	}
}

int main(void){
	init();
	
	int N;
	scanf("%d", &N);
	int ans=0;
	for(int i=0; i<N; i++){
		long long x, y=0;
		scanf("%lld", &x);
		long long l,r;
		r = floor(sqrt(x))+1;
		l = floor(sqrt(r-1))+1;
		while(v[r-1][y] - v[l-1][y]) y++;
		ans ^= y;
	}
	printf("%s", ans ? "koosaga" : "cubelover");
}
