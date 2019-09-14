#include <bits/stdc++.h>
using namespace std;
 
int a[4001];
int dp[4001];
int N;
 
int func(int now){
	if(now>=N) return 0;
	if(dp[now] != 987654321) return dp[now];
	int timemin = a[now] + 1740;
 
 
	// dp[now] = 140 + func(i+1)
	// dp[now] = 160 + func(i+2) or a[i] + 80- a[now]+1740 + func(i+2)
 
	dp[now] = 140+func(now+1);
	for(int i=now+2; i<=N; i++){
		int temp = max(timemin+120+(i-now)*20, a[i-1]+80);
		//cout << "temp : " << temp << endl;
		dp[now] = min(dp[now], func(i)+temp-timemin);
		//cout << "dp[" << i << "] : " << dp[i] << endl;
	}
	return dp[now];
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	cin >> N;
	for(int i=0; i<N; i++) cin >> a[i], dp[i] = 987654321;
	cout << func(0);
	return 0;
}
