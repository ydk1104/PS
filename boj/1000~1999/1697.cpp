#include<stdio.h>
#define INT_MAX 100000

int Queue[2*INT_MAX];
int start, end;
int dp[INT_MAX+1];
int N, K;

int check(int x){
	if(x>INT_MAX || x<0) return 1;
	if(dp[x]) return 1;
	dp[x]++; return 0;
}

void push(int x){
	if(check(x)) return;
	Queue[end++] = x;
	end %= (2*INT_MAX);
}

int pop(void){
	int temp = Queue[start++];
	start %= (2*INT_MAX);
	return temp;
}

int main(void){
	scanf("%d %d", &N, &K);
	push(N);
	int now = pop();
	push(now+1); push(now-1); push(now*2);
	int cnt = 0;
	while(now != K){
		int temp = end;
		while(start<temp && now!= K){
			now = pop();
//			printf("%d %d\n", now, cnt);
			push(now+1); push(now-1); push(now*2);
		}
		cnt++;
	}
	printf("%d", cnt);
}
