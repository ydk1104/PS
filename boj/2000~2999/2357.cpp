#include<stdio.h>

const int STMAX=1<<18;

struct MM{
	int max;
	int min;
	MM():max(0),min(2000000000){};
	MM(int a, int b):max(a),min(b){};
	MM maxmin(MM x){
		int Max = max>x.max?max:x.max;
		int Min = min<x.min?min:x.min;
		return MM(Max,Min);
	}
};

struct segeTree{
	MM a[STMAX];
	void update(int x, int i){
		a[i] = MM(x,x);
		while(i){
			i/=2;
			a[i] = a[2*i].maxmin(a[2*i+1]);
		}
	}
	MM find(int left, int right){return find(left, right, 1, STMAX/2, 1);}
	MM find(int left, int right, int nl, int nr, int now){
		if(nl>right || nr<left) return MM();
		if(nl>=left && nr<=right) return a[now];
		int mid = (nl+nr)/2;
		return find(left, right, nl, mid, now*2).maxmin(find(left, right, mid+1, nr, now*2+1));
	}
}ST;

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x);
		ST.update(x, STMAX/2+i);
	}
	for(;M--;){
		int x, y;
		scanf("%d %d", &x, &y);
		MM temp = ST.find(x, y);
		printf("%d %d\n", temp.min, temp.max);
	}
}
