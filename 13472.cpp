#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[200001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	/* code */
	ll N;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> a[i];
	}	
	sort(a, a+N);
	for(int i=2; i<N; i++){
		if(a[i] < a[i-1] + a[i-2]){
			cout << "possible"; 
			return 0;
		}
	}
	cout << "impossible";
	return 0;
}
