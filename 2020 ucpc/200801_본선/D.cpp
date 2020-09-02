#include<stdio.h>
#include<vector>
#include<algorithm>

using ll = long long;

std::vector<int> up;
std::vector<int> down;
std::vector<std::pair<int, ll> > e[6001];

ll edge[3011][3011];

ll square(ll x){
	return x*x;
}


ll visited[6001] = {0, };
ll ans = 0;
void dfs(int now, int prev, ll s){
	ans += s;
	for(auto &i : e[now]){
		if(i.first != prev){
			dfs(i.first, now, s+i.second);
		}
	}
}

int main(void){
	int N, M, L;
	scanf("%d %d %d", &N, &M, &L);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			edge[i][j] = -1;
		}
	}
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x);
		up.push_back(x);
	}
	for(int i=0; i<M; i++){
		int x;
		scanf("%d", &x);
		down.push_back(x);
	}
	
	std::vector<std::pair<int, int> > up_down;
	for(auto i:up){
		up_down.push_back({i, 0});
	}
	for(auto i:down){
		up_down.push_back({i, 1});
	}
	std::sort(up_down.begin(), up_down.end());
	
	ll upoint = 0;
	ll dpoint = 0;
	ll cpoint = 0;
	for(int i=0; i<up_down.size(); i++){
		auto cp = up_down[i];
		int cow = cp.first, dir = cp.second;
		if(dir == 0){
			upoint += 1;
			if(upoint == 1){
				for(int i=0; i<dpoint; i++){
					edge[0][i] = square(up[0] - down[i]);
				}
			}
			else if(dpoint >= 1){
				edge[upoint-1][dpoint-1] = square(up[upoint-1] - down[dpoint-1]);
			}
			if((upoint >= 2) && (dpoint >= 2)){
				cpoint = dpoint;
				ll bonus = 0;
				while(cpoint >= 2){
					bonus = square( (up[upoint - 2]) - (down[cpoint - 1]) ) - square( up[upoint-1] - down[cpoint-2] );
					if(bonus > 0){
						edge[upoint-2][cpoint-1] = -1;
						edge[upoint-1][cpoint-2] = square(up[upoint-1] - down[cpoint-2]);
						cpoint--;
					}
					else{
						break;
					}
				}
			}			
		}
		
		if(dir == 1){
			dpoint += 1;
			if(dpoint == 1){
				for(int i=0; i<upoint; i++){
					edge[i][0] = square((up[i] - down[0]));
				}
			}
			else if(upoint >= 1){
				edge[upoint-1][dpoint-1] = square(up[upoint-1] - down[dpoint-1]);
			}
			if((upoint >= 2) && (dpoint >= 2)){
				cpoint = upoint;
				ll bonus = 0;
				while(cpoint >= 2){
					bonus = square( (up[cpoint - 1]) - (down[dpoint - 2]) ) - square( up[cpoint-2] - down[dpoint-1] );
					if(bonus > 0){
						edge[cpoint-1][dpoint-2] = -1;
						edge[cpoint-2][dpoint-1] = square(up[cpoint-2] - down[dpoint-1]);
						cpoint--;
					}
					else{
						break;
					}
				}
			}			
		}
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(edge[i][j] != -1){
				e[i].push_back({j+N, edge[i][j] + L*L});
				e[j+N].push_back({i, edge[i][j] + L*L});
			}
		}
	}
	
	for(int i=0; i<N+M; i++){
		for(int j=0; j<N+M; j++){
			visited[j] = 0;
		}
		dfs(i, -1, 0);
	}
	printf("%lld", ans/2);
	
}
