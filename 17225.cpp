#include<stdio.h>
#include<vector>
#include<algorithm>

std::vector<std::pair<int, int> > v;

int main(void){
	int ab[2], tab[2]={0,}, M;
	scanf("%d %d %d", &ab[0], &ab[1], &M);
	for(int i=0; i<M; i++){
		int time, cnt, now;
		char type;
		scanf("%d %c %d", &time, &type, &cnt);
		if(type=='B') now=0;
		else now=1;
		if(tab[now] < time) tab[now] = time;
		for(int i=0; i<cnt; i++){
			v.push_back({tab[now], now});
			tab[now] += ab[now];
		}
	}
	std::sort(begin(v), end(v));
	int num=0;
	std::vector<int> ans[2];
	for(auto i:v){
		ans[i.second].push_back(++num);
	}
	for(int i=0; i<2; i++){
		printf("%d\n", ans[i].size());
		for(auto j:ans[i]){
			printf("%d ",j);
		}
		printf("\n");
	}
}
