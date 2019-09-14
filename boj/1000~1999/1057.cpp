#include<stdio.h>

typedef struct node{
	int pa;
	int cnt;
}node;

node uf[100001];
int queue[1000001];
int start;
int end;

void push(int N){
	queue[end] = N;
	end++;
	if(end>1000000){
		end = 0;
	}
	return;
}

int pop(void){
	int temp = queue[start];
	start++;
	if(start>1000000){
		start = 0;
	}
	return temp;
}

int sum(void){
	int a = pop();
	int b = pop();
	if(uf[a].cnt != uf[b].cnt){
		uf[a].cnt++;
		push(a);
		start--;
		return uf[a].cnt;
	}
	uf[b].pa = a;
	uf[a].cnt++;
	push(a);
	return uf[a].cnt;
}

int find(int N){
	if(uf[N].pa == N){
		return N;
	}
	uf[N].pa = find(uf[N].pa);
	return uf[N].pa;
}

int main(void){
	int N, a, b;
	scanf("%d %d %d", &N, &a, &b);
	for(int i=1; i<=N; i+=2){
		uf[i].pa = i;
		uf[i].cnt = 1;
		uf[i+1].pa = i;
		push(i);
	}
	int cnt = 1;
	while(find(a) != find(b)){
		cnt = sum();
	}
	printf("%d", cnt);
}
