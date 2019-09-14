#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
ll dp[1000001]={1,};
ll ans[1000001];
const ll modulo = 123456789ll;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	ll S, L;
	cin >> L >> S;
 
	if (S == 1ll) {
		cout << 1;
		return 0;
	}
 
	ll sum = 1ll;
	for (ll i = 1ll; i <= L; i++) {
		dp[i] = sum;
		sum += dp[i];
		if(i>=S) {
			sum-=dp[i-S];	
		}
		sum = (sum+modulo)%modulo;
//		 cout << dp[i] << '\n';
	}
	sum = 0;
	ll answer=0;
	for (ll i = L-S; i <= L; i++){
		ans[i] = sum;
		sum += dp[i];
		//if(i >= S+S) sum -= dp[i-S];
		sum = (sum+modulo)%modulo;
		answer += ans[i];
		answer = (answer+modulo)%modulo;
	}
	answer %= modulo;
	cout << answer;
	return 0;
}
