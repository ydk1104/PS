#include<stdio.h>
#include<vector>
using ll=long long;
ll fi[] = {1, 1};
ll map[1001][1001];
std::vector<ll> v;

int main(void){
	v.push_back(1);
	v.push_back(1);
	for(int i=2; ; i++){
		ll temp = v[i-1] + v[i-2];
		if(temp>0) v.push_back(temp);
		else break;
	}
	int i=1;
	while(i<94){
		ll temp = v[1] - v[0];
		v.insert(v.begin(), temp);
		i++;
	}
	int vsize = v.size();
	int atzero = 0;
	while(v[atzero]) atzero++;
	ll N, M;
	scanf("%lld %lld", &N, &M);
	int ans=0;
	for(ll i=0; i<M; i++){
		for(ll j=0; j<M; j++){
			scanf("%lld", &map[i][j]);
		}
	}
	if(M==1){
		ll ans=0;
		int x=0;
		for(int i=atzero+1; i<vsize; i++,x++){
			if(v[i] == **map) ans+=N-x;
			if(N-x==1) break;
		}
		x=1;
		for(int i=atzero; i>=0; i--,x++){
			if(v[i] == **map) ans+=N-x;
			if(N-x==1) break;
		}
		if(N==1 && M==1 && **map==1) ans++;
		printf("%lld",ans);
		return 0;
	}	
	while(ans<vsize && (v[ans] != map[0][0] || v[ans+1] != map[0][1])) ans++;
	if(ans==vsize) goto w;
	for(int i=0; i<M; i++){
		for(int j=0; j<M; j++){
			ll now = ans-i+j;
			if(now<0 || now>=vsize) goto w;
			if(map[i][j] != v[now]) goto w;
		}
	}
	ans -= atzero; 
	ans--;
	if(ans<0) ans=-ans;
	printf("%lld", N-M+1-ans);
	return 0;
	w:
		printf("0");
}
