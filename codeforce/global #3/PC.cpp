#include<stdio.h>
#include<unordered_map>
#include<vector>
#include<tuple>

using namespace std;

unordered_map<int, int> m;
int cnt, ans;
int a[300001];
vector<pair<int, int> > v;

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x);
		a[i] = x;
		if(x!=i+1) m[x] = i+1, cnt++;
	}
	while(cnt && !m.empty()){
		pair<int, int> now = *m.begin();
//		printf("test : %d %d\n",now.first, now.second);
//		printf("test : %d %d\n", m[now.second]);
		m[now.first] = m[now.second];
		if(2 * abs(now.second-m[now.second]) >= N)v.push_back({now.second, m[now.second]});
		else{
			int a1, b1;
			if(now.second > N/2) a1=1;
			else a1=N;
			if(m[now.second] > N/2) b1=1;
			else b1=N;
			v.push_back({now.second, a1});
			v.push_back({m[now.second], b1});
			ans+=1;
//			if(now.second == 1 || now.second == N) goto v;
//			if(m[now.second] == 1 || m[now.second] == N) goto v;
			if(a1==b1){
				v.push_back({now.second, a1});
				ans++;
				goto v;
			}
			v.push_back({1, N});
			v.push_back({now.second, a1});
			v.push_back({m[now.second], b1});
			ans+=3;
		}
		v:;
		if(now.first == m[now.second]) m.erase(m.begin()), cnt--;
		//m[now.second] = now.second;
		m.erase(m.find(now.second));
		ans++;
		cnt--;
	}
	printf("%d\n", ans);
	for(auto i:v){
		printf("%d %d\n", i.first, i.second);
	}
}
