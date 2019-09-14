#include<stdio.h>

int tree[101];

int find(int a, int b){
	int numa=0, numb=0;
	int ta=a, tb=b;
	while(tree[a] != 0){
		a = tree[a];
		numa++;
	}
	while(tree[b] != 0){
		b = tree[b];
		numb++;
	}
	int cnt = 0;
	if(numa<numb){
		for(int i=1; i<=numb-numa; i++){
			tb = tree[tb];
			cnt++;
		}
	}
	else if(numa>numb){
		for(int i=1; i<=numa-numb; i++){
			ta = tree[ta];
			cnt++;
		}
	}
	while((ta != tb) && (ta!=0)){
		ta = tree[ta];
		tb = tree[tb];
		cnt+=2;
	}
	if(ta == 0) return -1;
	return cnt;
}

int main(void){
	int N;
	scanf("%d", &N);
	int ta, tb;
	scanf("%d %d", &ta, &tb);
	int M;
	scanf("%d", &M);
	for(int i=1; i<=M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		tree[b] = a;
	}
	int ans = find(ta, tb);
	printf("%d", ans);
}
