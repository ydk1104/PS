#include<stdio.h>

typedef struct acm{
	int num;
	int time;
}acm;

int rule[1001][1001];
int time[1001];
acm PQ[10001];
int cnt = 0;

bool big(acm a, acm b){
	if(b.time == 0){
		return false;
	}
	if(a.time > b.time){
		return true;
	}
	return false;
}

void swap(acm *a, acm *b){
	acm temp = *a;
	*a = *b;
	*b = temp;
}

void put(int N, int t){
	cnt++;
	PQ[cnt].num = N;
	PQ[cnt].time = t;
	int i = cnt;
	while(big(PQ[i/2], PQ[i]) && i != 1){
		swap(&PQ[i/2], &PQ[i]);
		i = i/2;
	}
}

acm pop(void){
	acm re = PQ[1];
	PQ[1] = PQ[cnt];
	PQ[cnt] = PQ[0];
	cnt--;
	int i = 1;
	while(big(PQ[i], PQ[i*2]) || big(PQ[i], PQ[i*2+1])){
		if(big(PQ[i*2], PQ[i*2+1])){
			swap(&PQ[i], &PQ[i*2+1]);
			i = i*2+1;
		}
		else{
			swap(&PQ[i], &PQ[i*2]);
			i = i*2;
		}
	}
	return re;
}

int build(int W, int N){
	acm com = pop();
	if(com.num == W){
		return com.time;
	}
	for(int i=1; i<=N; i++){
		if(rule[com.num][i] == 1){
			rule[com.num][i] = 0;
			rule[0][i]--;
			if(rule[0][i] == 0){
				put(i, com.time+time[i]);
			}
		}
	}
	return build(W, N);
}

int main(void){
	int T;
	scanf("%d", &T);
	for (int ii=1; ii<=T; ii++){
		int N, K;
		scanf("%d %d", &N, &K);
		for (int i=1; i<=N; i++){
			scanf("%d", &time[i]);
		}
		for (int i=1; i<=K; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			rule[a][b] = 1;
			rule[0][b]++;
		}
		for (int i=1; i<=N; i++){
			if(rule[0][i] == 0){
				put(i, time[i]);
			}
		}
		int W;
		scanf("%d", &W);
		int ans = build(W, N);
		printf("%d\n", ans);
		for (int i=0; i<=N; i++){
			for (int j=1; j<=N; j++){
				rule[i][j] = 0;
			}
		}
		while(cnt>0){
			pop();
		}
	}
	return 0;
}
