#include<stdio.h>
#include<algorithm>

using namespace std;

class edge{
	public:
	int start;
	int end;
	int cost;
	bool operator <(edge &x){
		return this->cost<x.cost;
	}
};

edge E[210000];
int check[210000];

int find(int x){
	if(check[x] == -1) return x;
	return check[x] = find(check[x]);
}

int merge(int x, int y){
	int px = find(x);
	int py = find(y);
	if(px == py) return 0;
	check[py] = px;
	return 1;
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++) check[i] = -1;
	for(int i=0; i<M; i++){
		scanf("%d %d %d", &E[i].start, &E[i].end, &E[i].cost);
	}
	sort(E, E+M);
	int cnt = 1;
	int i = 0;
	int ans = 0;
	int nowcost = -1;
	while(cnt < N){
		int temp = i;
		while(E[i].cost == E[temp].cost && temp<M){
			if(find(E[temp].start) == find(E[temp].end)) E[temp].cost = -temp;
			temp++;
		}
		for(int j=i; j<temp; j++){
			if(E[j].cost > 0){
				if(merge(E[j].start, E[j].end)) cnt++;
				else ans++;
			}
		}
		i = temp;
	}
	printf("%d", ans);
}
