#include<stdio.h>
#define min(a,b) ((a)>(b)?(b):(a))
#define max(a,b) ((a)>(b)?(a):(b))

int a[20];
int oper[4]; // +, -, *, /
int MIN = 2000000000;
int MAX = -2000000000;
int N;

void BT(int o[4], int now, int nowsum){
//	printf("%d\n", nowsum);
	for(int i=0; i<4; i++){
		if(o[i] > oper[i]) return;
	}
	if(now>=N){
		MIN = min(MIN, nowsum);
		MAX = max(MAX, nowsum);
		return;
	}
	for(int i=0; i<4; i++){
		o[i]++;
		if(i==0) BT(o, now+1, nowsum+a[now]);
		if(i==1) BT(o, now+1, nowsum-a[now]);
		if(i==2) BT(o, now+1, nowsum*a[now]);
		if(i==3 && a[now]!=0) BT(o, now+1, nowsum/a[now]);
		o[i]--;
	}
}

int main(void){
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	for(int i=0; i<4; i++) scanf("%d", &oper[i]);
	int o[4] = {0, };
	BT(o, 1, a[0]);
	printf("%d\n%d", MAX, MIN);
}
