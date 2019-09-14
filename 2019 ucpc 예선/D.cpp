#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll mod = 1E9 + 7;

unordered_map<string, int> m;

ll dp[200001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string s, t;
		cin >> s;

		for (auto c : s) {
			t += c;
			if (m.count(t)) 
				m[t] = m[t] + 1;
			else 
				m[t] = 1;
		}
	}
	string w;


	cin >> w;

	int sz = w.size();

	dp[0] = m[string(1, w[0])];
	for (int i = 1; i < sz; i++) {
		if (i <= 300) {
			string t;
			for (int j = 0; j < i; j++) {
				t = w[i-j] + t;
				//cout << i-j << ' ' << t << ' ' << dp[i-j] << "*" << m[t] << '\n';
				dp[i] += dp[i-j-1] * m[t];
				if (dp[i] >= mod) {
					dp[i] %= dp[i];
				}
			}
			t = w[0] + t;
			dp[i] += m[t];
			if (dp[i] >= mod) {
					dp[i] %= dp[i];
			}
		} else {
			string t;
			for (int j = 0; j <= 300; j++) {
				t = w[i-j] + t;
				dp[i] += dp[i-j-1] * m[t];
				if (dp[i] >= mod) {
					dp[i] %= dp[i];
				}
			}
		}
	}

	cout << dp[sz-1]%mod;

	return 0;
}



