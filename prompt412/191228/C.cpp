#include<stdio.h>
#include<set>

std::pair<int, int> a[100001];

int map[100001];
std::set<int> set[100001];

void task(int type, int x, std::set<int>& now){
	if(type==1){
		if(now.find(x) != now.end()) now.erase(x);
		else now.insert(x);
	}
	if(type==2){
		now = set[x-1];
	}
	if(type==3){
		printf("%d\n", now.find(x) != now.end());
	}
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		if(i) set[i] = set[i-1];
		scanf("%d %d", &a[i].first, &a[i].second);
		task(a[i].first, a[i].second, set[i]);
	}
}
