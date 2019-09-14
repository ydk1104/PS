#include <bits/stdc++.h>
using namespace std;

struct minion{
	int atk;
	int hp;
} a;
int hps[13]={1,};

vector<minion> v;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	v.resize(N+M);
	if(N==0) {
		if (M == 0) {
			cout << "0";
			return 0;
		}
		for (int i = 0 ; i <M; i++) {
			cin >> v[i].atk >> v[i].hp;
		}
		bool flag = true;
		for (int i = 1; i <= 12; i++) {
			if (hps[i] > 0) {
				if (hps[i-1] == 0) {
					flag = false;
				}
			}
		}
		if (flag)
			cout << "1\nuse modok\n";
		else 
			cout << "-1";
		return 0;
	}

	for (int i = 0; i < N; i++) {
		cin >> a.atk >> a.hp;
		hps[a.hp]++;
	}
	for (int i = 0 ; i < M; i++) {
		cin >> v[i].atk >> v[i].hp;
		hps[v[i].hp]++;
	}

	if (M == 0) {
		cout << "0";
		return 0;
	}

	bool flag = true;
	for (int i = 1; i <= 12; i++) {
		if (hps[i] > 0) {
			if (hps[i-1] == 0) {
				flag = false;
			}
		}
	}
	if (flag) {
		cout << "1\nuse modok\n";
		return 0;
	}

	// case 1 때리고 모독
	for (int i = 0; i < M; ++i) {
		minion& b = v[i];
		int ahp = a.hp, bhp= b.hp;
		a.hp -= b.atk;
		b.hp -= a.atk;

		hps[ahp]--;
		if(a.hp>0)
			hps[a.hp]++;
		hps[bhp]--;
		if(b.hp>0)
			hps[b.hp]++;
		bool flag = true;
		for (int i = 1; i <= 12; i++) {
			if (hps[i] > 0) {
				if (hps[i-1] == 0) {
					flag = false;
				}
			}
		}
		if (flag) {
			cout <<"2\nattack 1 " << i+1 << "\nuse modok"; 
			return 0;
		}

		hps[ahp]++;
		if (a.hp>0)
		hps[a.hp]--;
		if(b.hp>0)
		hps[bhp]++;
		hps[b.hp]--;
		a.hp += b.atk;
		b.hp += a.atk;
	} 

	// case 2 모독 후 때리기
	bool onemore = true;
	int cnt = 0;
	while(onemore) {
		++cnt;
		onemore= false;
		if (hps[1] > 0) onemore = true;
		for (int i = 1; i < 12; i++) {
			hps[i-1] = hps[i];
		}
	}

	a.hp -= cnt;
	if (a.hp <= 0) {
		bool can = true;
		for (int i = 1; i < 12; i++) {
			if (hps[i] > 0) can = false;
		}
		if (can) {
			cout << "modok\n";
		} else {
			cout << "-1";
		}
		return 0;
	}

	hps[a.hp]--;
	int k = 0;
	int t;
	for (int i = 1 ; i < 12; i++) {

		if(hps[i] > 0) {
			if (i > a.atk) {
				cout << "-1";
				return 0;
			} 
			++k;
			t = i;
		}
	}
	if(k != 1) {
		cout << "-1";
	} else {
		cout << "2\nmodok\nattack 1 " << t << '\n'; 
	}

	return 0;
}
