#include<stdio.h>
#define QMAX 1000000

int stair[1000001];
int Queue[QMAX+1];
int start;
int end;
int F, S, G, U, D;

void push(int x){
	Queue[end++] = x;
	end %= QMAX;
}

int pop(){
	int temp = Queue[start++];
	start %= QMAX;
	return temp;
}

int BFS(){
	int cnt = 0;
	while(start!=end){
		int num = end-start;
		if(end<start) num+=QMAX;
		for(int i=1; i<=num; i++){
			int now = pop();
			if(now==G) return cnt;
			if((now>F) || (now<1)){}
			else if(stair[now] == -1){
				stair[now] = cnt;
				push(now+U), push(now-D);
			}
		}
		cnt++;
	}
	return -1;
}

int main(void){
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	for(int i=1; i<=F; i++){
		stair[i] = -1;
	}
	push(S);
	int ans = BFS();
	if(ans==-1) printf("use the stairs");
	else printf("%d", ans);
}
