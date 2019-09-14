#include<stdio.h>
#include<vector>

const int N_MAX=1000000;
const int ST_MAX = 1<<21;
using ll=long long;

struct segeTree{
	ll num[ST_MAX+1];
	ll laze[2*ST_MAX+1];
	void initialize(){
		for(int i=0; i<=ST_MAX; i++) num[i]=0;
		for(int i=0; i<=2*ST_MAX; i++) laze[i]=0;
	}
	// laze[now] = now�� �ش��ϴ� ������ laze[now]�� ���ؾ��Ѵٴ� �ǹ�
	// now�� �湮�� �� ����, laze[now]���� laze[2*now], laze[2*now+1]�� �̷�(update, ans �Լ��� propogate) 
	void propagate(int now, int len){
		laze[now*2] += laze[now];
		laze[now*2+1] += laze[now];
		num[now]+=len*laze[now];
		laze[now] = 0;
	}
	void update(int nl, int nr, int now, int left, int right, ll value){ // left~right�� value�� �߰� 
		propagate(now, (nr-nl+1));
		if(nl > right || nr < left) return;
		if(nl >= left && nr <= right){
			laze[now] += value;
			propagate(now, (nr-nl+1));
			return;
		}
		int mid = (nl+nr)/2;
		update(nl, mid, now*2, left, right, value), update(mid+1, nr, now*2+1, left, right, value);
		num[now] = num[2*now] + num[2*now+1];
	}
	ll ans(int nl, int nr, int now, int left, int right){ // left~right�� sum 
		propagate(now, nr-nl+1);
		if(nl > right || nr < left) return 0;
		if(nl >= left && nr <= right) return num[now];
		int mid = (nl+nr)/2;
		return ans(nl, mid, now*2, left, right)+ans(mid+1, nr, now*2+1, left, right);
	}
}ST;

int main(void){
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	for(int i=0; i<N; i++) scanf("%lld", &ST.num[i+ST_MAX/2]);
	for(int i=ST_MAX/2-1; i>0; i--) ST.num[i] = ST.num[i*2] + ST.num[i*2+1];
	for(int i=0; i<M+K; i++){
		int type, l, r;
		scanf("%d %d %d", &type, &l, &r);
		if(type==1){
			ll x;
			scanf("%lld", &x);
			ST.update(1, ST_MAX/2, 1, l, r, x);
		}
		else{
			printf("%lld\n", ST.ans(1, ST_MAX/2, 1, l, r));
		}
	}
}
