#include<stdio.h>
#include<vector>
#include<map>

using ll = long long;

std::vector<std::pair<ll, ll> > v;
std::pair<ll, ll> arr[150];
std::map<ll, int> m;
int cnt;

void push(long long N){
	if(N==0) return;
	if(N==1){
		return;
	}
	if(!m[N/2+N%2]){
		push(N/2+N%2);
	}
	if(!m[N/2]){
		push(N/2);
	}
	if(!m[N]){
		m[N] = ++cnt;
	}
	arr[m[N]] = {m[N/2+N%2], m[N/2]};
}

void solve(long long N){
	m.clear();
	for(int i=0; i<=cnt; i++) arr[i] = {0,0};
	cnt = 0;
	m[1] = ++cnt;
	scanf("%lld", &N);
	push(N);
	if(cnt > 125){
		printf("Error");
		exit(0);
	}
	printf("%d\n", cnt);
	for(int i=1; i<=cnt; i++){
		if(arr[i].first-1 >= i || arr[i].second-1 >= i){
			printf("Error");
			exit(0);
		}
		printf("%lld %lld\n", arr[i].first-1, arr[i].second-1);		
	}
	printf("%d\n", m[N]-1);
}

int main(void){
	int T;
	long long debug;
	for(scanf("%d", &T); T--;){
		solve(debug = (1LL<<62)+T);
	}
}
