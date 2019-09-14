#include<stdio.h>
#include<algorithm>
#include<queue>

using namespace std;

class edge{
	public:
	int start;
	int end;
	int cost;
	bool operator <(const edge &x)const{
		return this->cost>x.cost;
	}
};

priority_queue< edge, vector<edge>, less<edge> > pq;

//edge E[210000];
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
//		scanf("%d %d %d", &E[i].start, &E[i].end, &E[i].cost);
		edge temp;
		scanf("%d %d %d", &temp.start, &temp.end, &temp.cost);
		pq.push(temp);
	}
	edge max;
	max.cost = 2000000000;
	pq.push(max);
//	sort(E, E+M);
	int cnt = 1;
	int i = 0;
	int ans = 0;
	int nowcost = -1;
	edge temp = pq.top(); pq.pop();
	while(cnt < N){
		if(merge(temp.start, temp.end)){
			nowcost = temp.cost;
			cnt++;
		}
		else if(nowcost == temp.cost){
			temp.cost++;
			pq.push(temp);
			ans++;
		}
		temp = pq.top(); pq.pop();
	}
	while(nowcost == temp.cost && !pq.empty()){
		ans++;
		temp = pq.top(); pq.pop();
	}
//	if(pq.empty() == 0 && nowcost == temp.cost) ans++;
	printf("%d", ans);
}
