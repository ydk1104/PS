#include<stdio.h>

class sege{
	public:
	int N, K, temp;
	int a[300001];
	int cnt[300001];
	int cnt0[300001];
	void setup(){
		int temp = 1;
		while(temp<=N) temp*=2;
		N = temp;
		for(int i=1; i<=2*N; i++){
			a[i] = 1;
			cnt[i] = 0;
			cnt0[i] = 0;
		}
	}
	void update(int a[], int now, int sum){
		for(; now>=1; now/=2) a[now] += sum;
	}
	void change(int i, int x){
		if(a[i]==0) update(cnt0, i+N-1, -1);
		if(a[i]<0) update(cnt, i+N-1, -1);
		a[i] = x;
		if(x>0) return;
		if(x==0) update(cnt0, i+N-1, 1);
		if(x<0) update(cnt, i+N-1, 1);
	}
	int read(int a[], int l, int r, int nl, int nr, int now){
		if(l>nr || r<nl) return 0;
		if(nl >= l && r >= nr) return a[now];
		return read(a, l, r, nl, (nl+nr)/2, now*2) + read(a, l, r, (nl+nr)/2+1, nr, now*2+1);
	}
	void print(int left, int right){
		if(read(cnt0, left, right, 1, N, 1)){
			printf("0");
		}
		else{
			int temp = read(cnt, left, right, 1, N, 1);
			if(temp%2) printf("-");
			else printf("+");
		}
	}
};

sege game;
int temp, i, j, x; 

int main(void){
	while(~scanf("%d %d", &game.N, &game.K)){
		int temp = game.N;
		game.setup();
		for(i=1; i<=temp; i++){
			scanf("%d", &x);
			game.change(i, x);
		}
		getchar();
		for(j=0; j<game.K; j++){
			char c;
			scanf("%c", &c);
			scanf("%d %d", &i, &x);
			if(c == 'C') game.change(i, x);
			else game.print(i, x);
			getchar();
		}
		printf("\n");
	}
}
