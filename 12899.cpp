#include<stdio.h>

struct segeTree{
	int value[1<<22];
	int MAX = 1<<21;
	void update(int x){
		x+=MAX;
		value[x]++;
		while(x){
			x/=2;
			value[x] = value[2*x] + value[2*x+1];
		}
	}
	void K(int now, int x){
		while(now <= MAX){
			if(value[now*2] >= x){
				now = now*2;
			}
			else{
				x -= value[now*2];
				now = now*2+1;
			}
		}
		printf("%d\n", now-MAX);
		value[now] -= 2;
		update(now-MAX);
		return;
	}
}ST;

void push(int x){
	ST.update(x);
}

void pop(int x){
	ST.K(1, x);
}

int main(void){
	int N;
	scanf("%d", &N);
	void (*func[2])(int) = {push, pop};
	for(int i=0; i<N; i++){
		int t,x;
		scanf("%d %d", &t, &x);
		func[t-1](x);
	}
}
