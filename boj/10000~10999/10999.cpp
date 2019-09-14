#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
struct fenwick {
	ll arr[1000055];
	void update(int i, ll x) {
		while (i <= 1000005) {
			arr[i] += x;
			i += i & -i;
		}
	}
	ll sum(int i) const {
		ll x = 0;
		while (i) {
			x += arr[i];
			i -= i & -i;
		}
		return x;
	}
} suma, sumb;
 
int main() {
	int q;
	scanf("%d", &q);
	while (q--) {
		for(int i=1; i<=4; i++) printf("%d ", suma.arr[i]);
		printf("\n");
		for(int i=1; i<=4; i++) printf("%d ", sumb.arr[i]);
		printf("\n\n");
		int t, l, r;
		scanf("%d %d %d", &t, &l, &r);
		if (t == 1) {
			int x;
			scanf("%d", &x);
			suma.update(l, x); suma.update(r + 1, -x);
			sumb.update(l, (1ll - l) * x); sumb.update(r + 1, 1ll * r * x);
		}
		else {
			ll ans = 0;
			ans += suma.sum(r) * r + sumb.sum(r);
			ans -= suma.sum(l - 1) * (l - 1) + sumb.sum(l - 1);
			printf("%lld\n", ans);
		}
	}
	return 0;
}
