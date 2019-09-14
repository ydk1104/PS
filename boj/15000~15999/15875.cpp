#include<stdio.h>
#include<vector>
#include<algorithm>
#define MAXN 1001

using namespace std;

struct acid{
	int h;
	int check;
	int cnt;
	acid *pa;
	acid() : h(0), check(0), cnt(1), pa(0){}
	bool operator <(acid &x)const{return this->h<x.h;}
}map[MAXN+1][MAXN+1];

acid Q[MAXN*MAXN+1];
int cnt;

void push(acid x){Q[cnt++] = x;}

acid* find(acid* x){return x->pa==x ? x : x->pa=find(x->pa);}

void merge(acid* x, acid* y){
	if(x->h < y->h) return;
	x=find(x); y=find(y);
	if(x==y) return;
	y->pa = x;
	x->check *= y->check;
	if(x->check) x->cnt+=y->cnt;
	else x->cnt=0;
}

int main(void){
	int H, W;
	scanf("%d %d", &H, &W);
	for(int i=0; i<=H+1; i++) for(int j=0; j<=W+1; j++) map[i][j].pa = &map[i][j];
	for(int i=1; i<=H; i++){
		for(int j=1; j<=W; j++){
			scanf("%d", &map[i][j].h);
			map[i][j].check++;
			push(map[i][j]);
		}
	}
	sort(Q, Q+cnt);
	int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}, ans=0;
	for(int i=0; i<cnt;){
		int now=i;
		while(Q[now].h == Q[i].h){
			for(int j=0; j<4; j++) merge(Q[i].pa, Q[i].pa+dx[j]+dy[j]*(MAXN+1));
			i++;
		}
		for(int j=now; j<i; j++) ans = max(ans, find(Q[j].pa)->cnt);
	}
	printf("%d", ans);
}
